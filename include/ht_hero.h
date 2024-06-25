#ifndef HT_HERO_H
#define HT_HERO_H

#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_fixed_rect.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_camera_ptr.h"
#include "bn_log.h"

#include "bn_sprite_items_hero_running.h"
#include "bn_sound_items.h"

#include "ht_common.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

class hero : public object
{

public:
    enum class stat {
        IDLE,
        RUN
    };

    hero();

    static void collision_handler_func(ht::collision_manager::rect_body* body_a, ht::collision_manager::rect_body* body_b);
    void init();
    void key_event();
    void update();

    void set_position(const bn::fixed_point& pos);
    void set_visible(bool visible) { _sprite.set_visible(visible); }
    void set_camera(bn::camera_ptr& camera) { _sprite.set_camera(camera); }
    
    const bn::fixed_point get_position() { return _pos; }

private:
    ht::hero::stat _stat;
    ht::directions _current_direction;
    bn::fixed_point _pos;
    bn::fixed _speed;
    ht::collision_manager::rect_body* _rect_ptr;
    bn::sprite_ptr _sprite;

    bn::sprite_tiles_ptr _tiles_list[4] = {
        bn::sprite_items::hero_running.tiles_item().create_tiles(0),
        bn::sprite_items::hero_running.tiles_item().create_tiles(3),
        bn::sprite_items::hero_running.tiles_item().create_tiles(6),
        bn::sprite_items::hero_running.tiles_item().create_tiles(9),
    };
    bn::sprite_cached_animate_action<2> _action[4] = {
        bn::create_sprite_cached_animate_action_forever(
               _sprite, 16, bn::sprite_items::hero_running.tiles_item(), 1, 2),
        bn::create_sprite_cached_animate_action_forever(
               _sprite, 16, bn::sprite_items::hero_running.tiles_item(), 4, 5),
        bn::create_sprite_cached_animate_action_forever(
               _sprite, 16, bn::sprite_items::hero_running.tiles_item(), 7, 8),
        bn::create_sprite_cached_animate_action_forever(
               _sprite, 16, bn::sprite_items::hero_running.tiles_item(), 10, 11),
    };

    void _set_run();
    void _change_run();
    void _set_direction();
};

}

#endif
