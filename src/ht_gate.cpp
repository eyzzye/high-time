#include "ht_gate.h"

#include "bn_fixed.h"
#include "bn_log.h"

namespace ht
{

void gate::init(struct gate_init_data_t* init_data, int list_index) {
    _list_index = list_index;
    _body = &collision_manager::create_rect_body(
             collision_manager::body_type::STATIC,
             init_data->rect);
    _body->set_user_data((void*)this);

    _direction = init_data->direction;

    if ((_direction == ht::directions::UP) || (_direction == ht::directions::DOWN)) {
        int map_x = ((init_data->rect.x().right_shift_integer() - 32/2) + 512/2) / 8;
        int map_y = ((init_data->rect.y().right_shift_integer() - 16/2) + 512/2) / 8;
        _bg_map_pos[0] = bn::fixed_point(map_x  , map_y);
        _bg_map_pos[1] = bn::fixed_point(map_x+1, map_y);
        _bg_map_pos[2] = bn::fixed_point(map_x+2, map_y);
        _bg_map_pos[3] = bn::fixed_point(map_x+3, map_y);
        _bg_map_pos[4] = bn::fixed_point(map_x  , map_y+1);
        _bg_map_pos[5] = bn::fixed_point(map_x+1, map_y+1);
        _bg_map_pos[6] = bn::fixed_point(map_x+2, map_y+1);
        _bg_map_pos[7] = bn::fixed_point(map_x+3, map_y+1);
    }
    else {
        int map_x = ((init_data->rect.x().right_shift_integer() - 16/2) + 512/2) / 8;
        int map_y = ((init_data->rect.y().right_shift_integer() - 32/2) + 512/2) / 8;
        _bg_map_pos[0] = bn::fixed_point(map_x  , map_y);
        _bg_map_pos[1] = bn::fixed_point(map_x+1, map_y);
        _bg_map_pos[2] = bn::fixed_point(map_x  , map_y+1);
        _bg_map_pos[3] = bn::fixed_point(map_x+1, map_y+1);
        _bg_map_pos[4] = bn::fixed_point(map_x  , map_y+2);
        _bg_map_pos[5] = bn::fixed_point(map_x+1, map_y+2);
        _bg_map_pos[6] = bn::fixed_point(map_x  , map_y+3);
        _bg_map_pos[7] = bn::fixed_point(map_x+1, map_y+3);
    }
}

void gate::open() {
    _body->set_stat(ht::collision_manager::body_stat::INACTIVE);
}

void gate::close() {
    _body->set_stat(ht::collision_manager::body_stat::ACTIVE);
}

bool gate::on_gate(bn::fixed_point& pos) {
    auto x = pos.x();
    auto y = pos.y();

    const bn::fixed_rect* rect_ptr = &_body->rect();
    auto x1 = rect_ptr->x() - (rect_ptr->width() / 2);
    auto y1 = rect_ptr->y() - (rect_ptr->height() / 2);
    auto x2 = rect_ptr->x() + (rect_ptr->width() / 2);
    auto y2 = rect_ptr->y() + (rect_ptr->height() /2);

    // AABB box
    if (((x1 <= x) && (x <= x2)) && ((y1 <= y) && (y <= y2)))
    {
        return true;
    }

    return false;
}

}

