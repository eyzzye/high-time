#ifndef HT_SCENE_ENDING_H
#define HT_SCENE_ENDING_H

#include "bn_fixed.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_sprite_text_generator.h"

#include "bn_regular_bg_items_ending.h"
#include "bn_sprite_items_ending_arm.h"
#include "bn_sprite_items_ending_barrel.h"
#include "bn_sprite_items_ending_bird.h"
#include "bn_sprite_items_ending_shark.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_font_palette.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"

#include "ht_common.h"
#include "ht_scene.h"

namespace ht {

class ending : public scene {
public:
    enum class msg_stat {
        STORY,
        SCORE_TITLE,
        SCORE_DATA,
        THANKS,
        END,
    };

    ending();
    ~ending() = default;
    void update();

private:
    ht::ending::msg_stat _msg_stat;
    bn::regular_bg_ptr _background;

    // message sprite
    bn::sprite_text_generator _text_generator;
    bn::vector<bn::sprite_ptr, 32> _text_sprites1;
    bn::vector<bn::sprite_ptr, 32> _text_sprites2;
    int _msg_time;

    // animation sprite
    bn::sprite_ptr _hero_arm_ptr;
    bn::sprite_ptr _barrel_ptr;
    bn::sprite_ptr _bird_ptr;
    bn::sprite_ptr _shark_ptr;
    int _anim_index;
    int _animation_time;
    bn::fixed _bird_pos_x;
    bn::fixed _shark_pos_x;
    bn::fixed _shark_vel_x;

    void _set_next_msg();
};

}

#endif
