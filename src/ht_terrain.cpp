#include "ht_terrain.h"

namespace ht
{

void terrain::init(struct array_t<terrain_init_data_t>* init_list) {
    _rect_ptr_list.clear();

    for (int i = 0; i < (int)init_list->size; i++) {
        ht::collision_manager::rect_body* rect_ptr =
            &collision_manager::create_rect_body(collision_manager::body_type::STATIC,
                                                 init_list->data[i].collision_rect_list);
        rect_ptr->set_user_data((void*)this);
        _rect_ptr_list.push_back(rect_ptr);
    }
}

}

