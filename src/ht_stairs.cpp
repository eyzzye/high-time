#include "ht_stairs.h"

#include "bn_fixed.h"

namespace ht
{

void stairs::init(struct stairs_init_data_t* init_data) {
    bn::fixed_rect stairs_rect(init_data->pos.x(), init_data->pos.y(), 16, 16);
    ht::collision_manager::rect_body* rect_ptr =
        &collision_manager::create_rect_body(collision_manager::body_type::DYNAMIC,
                                             stairs_rect);
    rect_ptr->set_user_data((void*)this);

    _next_floor = init_data->next_floor;
    _next_floor_pos = init_data->next_floor_pos;
}

}

