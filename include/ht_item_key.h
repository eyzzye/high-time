#ifndef HT_ITEM_KEY_H
#define HT_ITEM_KEY_H

#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"

#include "bn_sprite_items_item_key.h"

#include "ht_common.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

struct item_key_init_data_t {
    bn::fixed_rect rect;
};

class item_key : public object {
public:
    item_key():
        object(ht::object::type::ITEM, (int)ht::object::item_id::ITEM_KEY),
        _body(NULL),
        _sprite(bn::sprite_items::item_key.create_sprite(0, 0))
    {}

    item_key(struct item_key_init_data_t* init_data, int list_index):
        item_key()
    {
        init(init_data, list_index);
    }

    void init(struct item_key_init_data_t* init_data, int list_index);
    int get_list_index() { return _list_index; }
    void set_camera(bn::camera_ptr& camera) { _sprite.set_camera(camera); }
    void set_enable(bool on);

private:
    int _list_index;
    ht::collision_manager::rect_body* _body;
    bn::sprite_ptr _sprite;
};

}
#endif
