#ifndef HT_TELEPORT_H
#define HT_TELEPORT_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"

#include "bn_sprite_items_mark_tiles.h"

#include "ht_common.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

struct teleport_init_data_t {
    bn::fixed_rect rect;
    int next_floor;
    bn::fixed_point next_floor_pos;
};

class teleport : public object {
public:
    teleport():
        object(ht::object::type::EVENT, (int)ht::object::event_id::TELEPORT),
        _next_floor(0),
        _next_floor_pos(0,0),
        _enable(true),
        _blink_time(0)
    {}

    teleport(struct teleport_init_data_t* init_data):
        teleport()
    {
        init(init_data);
    }

    void init(struct teleport_init_data_t* init_data);
    int get_next_floor() { return _next_floor; }
    bn::fixed_point get_next_floor_pos() { return _next_floor_pos; }

    void update();
    void set_enable(bool on);
    void set_camera(bn::camera_ptr& camera);

private:
    int _next_floor;
    bn::fixed_point _next_floor_pos;

    bool _enable;
    bn::fixed _blink_time;
    bn::vector<bn::sprite_ptr, 8> _sprite;
};

}
#endif
