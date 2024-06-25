#ifndef HT_GOAL_H
#define HT_GOAL_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_camera_ptr.h"

#include "bn_sprite_items_mark_tiles.h"

#include "ht_common.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

class goal : public object {
public:
    goal():
        object(ht::object::type::EVENT, (int)ht::object::event_id::GOAL),
        _enable(true),
        _blink_time(0)
    {}

    void init(const bn::fixed_rect& goal_region);
    void destroy() { _sprite.clear(); }
    void update();
    void set_enable(bool on);
    void set_camera(bn::camera_ptr& camera);

private:
    bool _enable;
    bn::fixed _blink_time;
    bn::vector<bn::sprite_ptr, 16> _sprite;
};

}
#endif
