#include "ht_teleport.h"

#include "bn_fixed.h"

namespace ht
{

static const int teleport_blink_time = 50;

void teleport::init(struct teleport_init_data_t* init_data) {
    ht::collision_manager::rect_body* rect_ptr =
        &collision_manager::create_rect_body(collision_manager::body_type::DYNAMIC,
                                             init_data->rect);
    rect_ptr->set_user_data((void*)this);

    _next_floor = init_data->next_floor;
    _next_floor_pos = init_data->next_floor_pos;

    // set _sprite
    int x_count = init_data->rect.width().right_shift_integer() / 16;
    int y_count = init_data->rect.height().right_shift_integer() / 16;
    int x_start = init_data->rect.x().right_shift_integer() - (init_data->rect.width().right_shift_integer() / 2) + 8;
    int y_start = init_data->rect.y().right_shift_integer() - (init_data->rect.height().right_shift_integer() / 2) + 8;

    for (int y_idx = 0; y_idx < y_count; y_idx++) {
        bn::fixed pos_y = y_start + y_idx * 16;
        for (int x_idx = 0; x_idx < x_count; x_idx++) {
            bn::fixed pos_x = x_start + x_idx * 16;
            _sprite.emplace_back(
              bn::sprite_items::mark_tiles.create_sprite(pos_x,pos_y,2));
        }
    }

    // set direction
    ht::directions sprite_direction = ht::directions::RIGHT;
    if (init_data->rect.x() > init_data->next_floor_pos.x()) {
        //sprite_direction = ht::directions::RIGHT;
    }
    else if (init_data->rect.x() < init_data->next_floor_pos.x()) {
        sprite_direction = ht::directions::LEFT;
    }
    else if (init_data->rect.y() > init_data->next_floor_pos.y()) {
        sprite_direction = ht::directions::DOWN;
    }
    else if (init_data->rect.y() < init_data->next_floor_pos.y()) {
        sprite_direction = ht::directions::UP;
    }

    if (sprite_direction != ht::directions::RIGHT) {
        for (int i = 0; i < _sprite.size(); i++) {
            if (sprite_direction == ht::directions::LEFT) {
                _sprite[i].set_horizontal_flip(true);
            }
            else if (sprite_direction == ht::directions::DOWN) {
                _sprite[i].set_rotation_angle(270);
            }
            else if (sprite_direction == ht::directions::UP) {
                _sprite[i].set_rotation_angle(90);
            }
        }
    }   
}

void teleport::update() {
    // blink region mark
    _blink_time += 1;
    if (_blink_time > teleport_blink_time) {
        set_enable(!_enable);
        _blink_time = 0;
    }
}

void teleport::set_enable(bool on) {
    if (_enable == on) return;

    for (int i = 0; i < _sprite.size(); i++) {
        _sprite[i].set_visible(on);
    }

    _enable = on;
}

void teleport::set_camera(bn::camera_ptr& camera) {
    for (int i = 0; i < _sprite.size(); i++) {
        _sprite[i].set_camera(camera);
    }
}

}

