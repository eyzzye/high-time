#ifndef HT_ENEMY_ASSASSIN_H
#define HT_ENEMY_ASSASSIN_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_fixed_rect.h"
#include "bn_memory.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_animate_actions.h"
#include "bn_log.h"

#include "bn_sprite_items_assassin.h"
#include "bn_sprite_items_mark_tiles.h"

#include "ht_common.h"
#include "ht_object.h"
#include "ht_enemy.h"
#include "ht_collision_manager.h"
#include "ht_trace_manager.h"

namespace ht {

class assassin : public enemy
{
public:
    assassin(ht::enemy::grade grade_val = grade::NORMAL);
    assassin(ht::enemy::grade grade_val,
             bn::fixed_point& pos_ref,
             struct ai_scenario_t* ai_list, int size);

    static void collision_handler_func(ht::collision_manager::rect_body* body_a, ht::collision_manager::rect_body* body_b);
    void update();

    void set_position(bn::fixed_point& pos);
    void set_ai_scenario(struct ai_scenario_t* ai_list, int size);
    void set_visible(bool visible) {
        _sprite.set_visible(visible);
        if (_target_sprite != nullptr) { _target_sprite->set_visible(visible); }
    }
    void set_camera(bn::camera_ptr& camera) {
        _sprite.set_camera(camera);
        if (_target_sprite != nullptr) { _target_sprite->set_camera(camera); }
    }

private:
    ht::enemy::grade _grade;
    ht::enemy_stat _stat;
    ht::directions _current_direction;
    bn::fixed_point _pos;
    bn::fixed _speed;
    ht::collision_manager::rect_body* _rect_ptr;
    struct ai_stat_t _ai_stat;
    bn::vector<struct ai_scenario_t, 16> _ai_scenario;
    ht::trace_manager::trace_list_t* _trace;

    bn::sprite_ptr _sprite;
    struct animation_data_t _anim = {0,0,0,NULL,0};

    bn::unique_ptr<bn::sprite_ptr> _target_sprite;
    int _blink_target_time;
    bool _target_enable;

    void _update_trace(bn::fixed_point& new_pos, bool& vel_zero_flg);
    void _set_tiles(int index);
    void _set_direction();
    void _init_animation();
    void _update_animation();
    void _set_target_enable(bool on);
};

}

#endif
