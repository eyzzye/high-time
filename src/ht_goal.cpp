#include "ht_goal.h"

namespace ht
{

#define HT_GOAL_BLINK_TIME (50)

void goal::init(const bn::fixed_rect& goal_region) {
    ht::collision_manager::rect_body* rect_ptr =
        &collision_manager::create_rect_body(collision_manager::body_type::DYNAMIC,
                                             goal_region);
    rect_ptr->set_user_data((void*)this);

    // set _sprite
    int x_count = goal_region.width().right_shift_integer() / 16;
    int y_count = goal_region.height().right_shift_integer() / 16;
    int x_start = goal_region.x().right_shift_integer() - (goal_region.width().right_shift_integer() / 2) + 8;
    int y_start = goal_region.y().right_shift_integer() - (goal_region.height().right_shift_integer() / 2) + 8;
    for (int y_idx = 0; y_idx < y_count; y_idx++) {
        bn::fixed pos_y = y_start + y_idx * 16;
        for (int x_idx = 0; x_idx < x_count; x_idx++) {
            bn::fixed pos_x = x_start + x_idx * 16;
            _sprite.emplace_back(
                bn::sprite_items::mark_tiles.create_sprite(pos_x,pos_y,0));
        }
    }
}

void goal::update() {
    // blink region mark
    _blink_time += 1;
    if (_blink_time > HT_GOAL_BLINK_TIME) {
        set_enable(!_enable);
        _blink_time = 0;
    }
}

void goal::set_enable(bool on) {
    if (_enable == on) return;

    for (int i = 0; i < _sprite.size(); i++) {
        _sprite[i].set_visible(on);
    }

    _enable = on;
}

void goal::set_camera(bn::camera_ptr& camera) {
    for (int i = 0; i < _sprite.size(); i++) {
        _sprite[i].set_camera(camera);
    }
}

}

