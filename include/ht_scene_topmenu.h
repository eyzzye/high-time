#ifndef HT_SCENE_TOPMENU_H
#define HT_SCENE_TOPMENU_H

#include "bn_fixed.h"
#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "bn_regular_bg_items_title240x160.h"
#include "bn_sprite_items_hero_running.h"
#include "common_variable_8x16_sprite_font.h"
#include "bn_sprite_items_font_palette.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"

#include "ht_common.h"
#include "ht_scene.h"

namespace ht {

class topmenu : public scene {
public:
    topmenu();
    ~topmenu() = default;
    void update();

private:
    bn::regular_bg_ptr _background;
    bn::sprite_ptr _hero;
    bn::sprite_text_generator _text_generator;
    bn::vector<bn::sprite_ptr, 16> _text_sprites;
};

}

#endif
