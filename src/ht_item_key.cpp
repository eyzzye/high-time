#include "ht_item_key.h"

#include "bn_fixed.h"

namespace ht
{

void item_key::init(struct item_key_init_data_t* init_data, int list_index) {
    _list_index = list_index;
    _body = &collision_manager::create_rect_body(
             collision_manager::body_type::DYNAMIC,
             init_data->rect);
    _body->set_user_data((void*)this);

    // set sprite position
    _sprite.set_x(init_data->rect.x());
    _sprite.set_y(init_data->rect.y());
}

void item_key::set_enable(bool on) {
    if (on) {
        _body->set_stat(ht::collision_manager::body_stat::ACTIVE);
        _sprite.set_visible(true);
    }
    else {
        _body->set_stat(ht::collision_manager::body_stat::INACTIVE);
        _sprite.set_visible(false);
    }
}

}

