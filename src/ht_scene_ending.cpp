#include "ht_scene_ending.h"

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_music_actions.h"

#include "ht_score.h"

extern ht::scene::type next_scene;
extern ht::score g_score;

namespace ht {

static const int ending_msg_time = 600;
static const int ending_animation_time = 50;

ending::ending():
    scene(scene::type::ENDING),
    _msg_stat(ht::ending::msg_stat::STORY),
    _background(bn::regular_bg_items::ending.create_bg(0, 0)),
    _text_generator(common::variable_8x16_sprite_font,
                    bn::sprite_items::font_palette.palette_item()),
    _msg_time(0),
    _hero_arm_ptr(bn::sprite_items::ending_arm.create_sprite(41,21,0)),
    _barrel_ptr(bn::sprite_items::ending_barrel.create_sprite(1,31,0)),
    _bird_ptr(bn::sprite_items::ending_bird.create_sprite(144,-30,0)),
    _shark_ptr(bn::sprite_items::ending_shark.create_sprite(-98,32,0)),
    _anim_index(0),
    _animation_time(0),
    _bird_pos_x(144),
    _shark_pos_x(-98),
    _shark_vel_x(0.3f)
{
    bn::music_items::ending.play(0.5);

#if 0
    // Test code
    g_score.time[0] = 194;
    g_score.time[1] = 195;
    g_score.time[2] = 196;
    g_score.time[3] = 197;
    g_score.died[0] = 99;
    g_score.died[1] = 99;
    g_score.died[2] = 99;
    g_score.died[3] = 99;
#endif

    _text_generator.set_center_alignment();
    _text_generator.generate(0, 48, "We've got a brand-new home.", _text_sprites1);
    _text_generator.generate(0, 64, "So, what shall we do?", _text_sprites2);

    set_stat(scene::stat::ACTIVE);
}

void ending::update() {
    if (get_stat() != scene::stat::ACTIVE) return;

    // update animation
    _animation_time += 1;
    if (_animation_time > ending_animation_time) {
        _animation_time = 0;
        if (_anim_index == 0) {
            _anim_index += 1;
        } else {
            _anim_index = 0;
        }
        _hero_arm_ptr.set_tiles(bn::sprite_items::ending_arm.tiles_item().create_tiles(_anim_index));
        _barrel_ptr.set_tiles(bn::sprite_items::ending_barrel.tiles_item().create_tiles(_anim_index));
        _bird_ptr.set_tiles(bn::sprite_items::ending_bird.tiles_item().create_tiles(_anim_index));
        _shark_ptr.set_tiles(bn::sprite_items::ending_shark.tiles_item().create_tiles(_anim_index));
    }

    // update bird position
    if (_bird_pos_x > -144) {
        _bird_pos_x = _bird_pos_x - 0.2f;
    }
    else {
        _bird_pos_x = 144;
    }
    _bird_ptr.set_x(_bird_pos_x);

    // update shark position
    if (_shark_pos_x < -98) {
        _shark_vel_x = -_shark_vel_x;
        _shark_ptr.set_horizontal_flip(false);
    }
    else if (_shark_pos_x > -28) {
        _shark_vel_x = -_shark_vel_x;
        _shark_ptr.set_horizontal_flip(true);
    }
    _shark_pos_x += _shark_vel_x;
    _shark_ptr.set_x(_shark_pos_x);

    // update message
    if (_msg_stat != ht::ending::msg_stat::END) {
        _msg_time += 1;
        if (_msg_time > ending_msg_time) {
            _set_next_msg();
            _msg_time = 0;
        }
    }
    else if (_msg_stat == ht::ending::msg_stat::END) {
        if (bn::keypad::any_pressed()) {
            bn::music::stop();
            bn::sound_items::click1.play();
            next_scene = ht::scene::type::TOPMENU;
            set_stat(scene::stat::DONE);
        }
    }
    
    bn::core::update();
}

void ending::_set_next_msg() {
    if (_msg_stat == ht::ending::msg_stat::STORY) {
        _msg_stat = ht::ending::msg_stat::SCORE_TITLE;
        _text_sprites1.clear();
        _text_sprites2.clear();
        _text_generator.generate(0, 48, "Score: Time [Died]", _text_sprites1);
    }
    else if (_msg_stat == ht::ending::msg_stat::SCORE_TITLE) {
        _msg_stat = ht::ending::msg_stat::SCORE_DATA;
        _text_sprites1.clear();
        _text_sprites2.clear();

        char msg1[34] = "Stage1 00:00[00] Stage2 00:00[00]";
        char msg2[34] = "Stage3 00:00[00] Stage4 00:00[00]";
        for (int i = 0; i < HT_STAGE_MAX; i++) {
            char *time_str, *died_str;
            if (i==0) { time_str = &msg1[7];  died_str = &msg1[13]; }
            if (i==1) { time_str = &msg1[24]; died_str = &msg1[30]; }
            if (i==2) { time_str = &msg2[7];  died_str = &msg2[13]; }
            if (i==3) { time_str = &msg2[24]; died_str = &msg2[30]; }

            // time
            int minute = g_score.time[i] / 60;
            int second = g_score.time[i] % 60;

            int upper_num = 0;
            int under_num = 0;
            if (minute >= 10) {
                upper_num = minute / 10;
                under_num = minute % 10;
            }
            else if (minute > 0) {
                //upper_num = 0;
                under_num = minute;
            }
            *time_str = '0' + upper_num;
            *(time_str + 1) = '0' + under_num;

            upper_num = 0;
            under_num = 0;
            if (second >= 10) {
                upper_num = second / 10;
                under_num = second % 10;
            }
            else if (second > 0) {
                //upper_num = 0;
                under_num = second;
            }
            *(time_str + 3) = '0' + upper_num;
            *(time_str + 4) = '0' + under_num;

            // died
            int died_val = g_score.died[i];
            upper_num = 0;
            under_num = 0;
            if (died_val > 99) { died_val = died_val % 100; }
            if (died_val >= 10) {
                upper_num = died_val / 10;
                under_num = died_val % 10;
            }
            else if (died_val > 0) {
                //upper_num = 0;
                under_num = died_val;
            }
            *died_str = '0' + upper_num;
            *(died_str + 1) = '0' + under_num;
        }

        _text_generator.generate(0, 48, msg1, _text_sprites1);
        _text_generator.generate(0, 64, msg2, _text_sprites2);
    }
    else if (_msg_stat == ht::ending::msg_stat::SCORE_DATA) {
        _msg_stat = ht::ending::msg_stat::THANKS;
        _text_sprites1.clear();
        _text_sprites2.clear();
        _text_generator.generate(0, 48, "Thank you for playing!!", _text_sprites1);
    }
    else if (_msg_stat == ht::ending::msg_stat::THANKS) {
        _msg_stat = ht::ending::msg_stat::END;
        _text_sprites1.clear();
        _text_sprites2.clear();
        _text_generator.generate(0, 48, "THE END", _text_sprites1);
    }
}

}
