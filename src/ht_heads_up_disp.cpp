#include "ht_heads_up_disp.h"

#include "bn_display.h"
#include "bn_sprite_tiles_ptr.h"

#include "ht_time_manager.h"
#include "ht_object.h"

extern int g_hero_item_count[(int)ht::object::item_id::ITEM_MAX];

namespace ht {

hud::hud():
    _enable(true),
    _dirt_time(true),
    _time(0),
    _item_key_count(0)
{
    // time
    bn::fixed pos_x = (bn::display::width() / 2) - 16 * _time_sprite_size;
    bn::fixed pos_y = -(bn::display::height() / 2) + 16;
    for (int i = 0; i < _time_sprite_size; i++) {
        if (i == 2) {
            _time_sprite.emplace_back(
                bn::sprite_items::digit_numbers.create_sprite(pos_x,pos_y,10));
        }
        else {
            _time_sprite.emplace_back(
                bn::sprite_items::digit_numbers.create_sprite(pos_x,pos_y,0));
        }
        _time_sprite[i].set_z_order(HT_Z_ORDER_SPRITE_TOP);
        pos_x += 16;
    }

    // hero stat -> item_key
    pos_x = (bn::display::width() / 2) - 40;
    pos_y = (bn::display::height() / 2) - 16;
    for (int i = 0; i < _item_key_sprite_size; i++) {
        if (i == 0) {
            _item_key_sprite.emplace_back(
                bn::sprite_items::item_key.create_sprite(pos_x,pos_y));
            pos_x += 16;
        }
        else if (i == 1) {
            _item_key_sprite.emplace_back(
                bn::sprite_items::digit_numbers_8x16.create_sprite(pos_x,pos_y,12));
            pos_x += 8;
        }
        else {
            _item_key_sprite.emplace_back(
                bn::sprite_items::digit_numbers_8x16.create_sprite(pos_x,pos_y,0));
            pos_x += 8;
        }
        _item_key_sprite[i].set_z_order(HT_Z_ORDER_SPRITE_TOP);
    }

    set_enable(false);
}

void hud::update() {
    if (_dirt_time) {
        int minute = _time / 60;
        int second = _time % 60;

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
        _time_sprite[0].set_tiles(
            bn::sprite_items::digit_numbers.tiles_item().create_tiles(upper_num));
        _time_sprite[1].set_tiles(
            bn::sprite_items::digit_numbers.tiles_item().create_tiles(under_num));

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
        _time_sprite[3].set_tiles(
            bn::sprite_items::digit_numbers.tiles_item().create_tiles(upper_num));
        _time_sprite[4].set_tiles(
            bn::sprite_items::digit_numbers.tiles_item().create_tiles(under_num));

        // set palette red
        if (ht::time_manager::get_enemy_stat() == ht::time_manager::enemy_stat::ACTIVE) {
            set_palette_red(true);
        }
        else {
            set_palette_red(false);
        }

        _dirt_time = false;
    }

    // hero stat -> item_key
    if (_item_key_count != g_hero_item_count[(int)ht::object::item_id::ITEM_KEY]) {
        _item_key_count = g_hero_item_count[(int)ht::object::item_id::ITEM_KEY];

        int upper_num = 0;
        int under_num = 0;
        if (_item_key_count >= 10) {
            upper_num = _item_key_count / 10;
            under_num = _item_key_count % 10;
        }
        else if (_item_key_count > 0) {
            //upper_num = 0;
            under_num = _item_key_count;
        }
        _item_key_sprite[2].set_tiles(
            bn::sprite_items::digit_numbers_8x16.tiles_item().create_tiles(upper_num));
        _item_key_sprite[3].set_tiles(
            bn::sprite_items::digit_numbers_8x16.tiles_item().create_tiles(under_num));
    }
}

void hud::set_enable(bool on) {
    if (_enable == on) return;

    // time
    for (int i = 0; i < _time_sprite_size; i++) {
        _time_sprite[i].set_visible(on);
    }

    // hero stat -> item_key
    for (int i = 0; i < _item_key_sprite_size; i++) {
        _item_key_sprite[i].set_visible(on);
    }

    _enable = on;
}

void hud::set_time(int sec_time) {
    if (_time != sec_time) {
        _time = sec_time;
        _dirt_time = true;
    }
}

void hud::set_palette_red(bool on) {
    for (int i = 0; i < _time_sprite_size; i++) {
        if (on) {
            _time_sprite[i].set_palette(bn::sprite_items::digit_numbers_red.palette_item());
        }
        else {
            _time_sprite[i].set_palette(bn::sprite_items::digit_numbers.palette_item());
        }
    }
}

}

