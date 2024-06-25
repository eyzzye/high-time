#include "ht_scene_topmenu.h"

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_keypad.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_regular_bg_ptr.h"
#include "bn_music_actions.h"
#include "bn_log.h"

// extern variables
extern ht::scene::type next_scene;

namespace ht {

topmenu::topmenu():
    scene(scene::type::TOPMENU),
    _background(bn::regular_bg_items::title240x160.create_bg(0, 0)),
    _hero(bn::sprite_items::hero_running.create_sprite(0, 0)),
    _text_generator(common::variable_8x16_sprite_font,
                    bn::sprite_items::font_palette.palette_item())
{
    bn::music_items::music001.play(0.5);

    _text_generator.set_center_alignment();
    _text_generator.generate(0, 32, "PUSH START", _text_sprites);

    set_stat(scene::stat::ACTIVE);
}

void topmenu::update() {
    if (bn::keypad::start_pressed()) {
        bn::music::stop();
        bn::sound_items::click1.play();
        next_scene = ht::scene::type::GAME;
        set_stat(scene::stat::DONE);
    }

    bn::core::update();
}

}
