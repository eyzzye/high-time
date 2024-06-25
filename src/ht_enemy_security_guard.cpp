#include "ht_enemy_security_guard.h"

#include "ht_time_manager.h"

extern bn::fixed_point g_hero_pos;

namespace ht {

#define HT_THIS_CLASS_NAME security_guard
#include "ht_enemy_ai_move_to.cpp.h"

static struct animation_frame_data_t anim_run_down_data[] = {
    {1, 16},
    {2, 16},
};
static struct animation_frame_data_t anim_run_up_data[] = {
    {4, 16},
    {5, 16},
};
static struct animation_frame_data_t anim_run_right_data[] = {
    {7, 16},
    {8, 16},
};
static struct animation_frame_data_t anim_run_left_data[] = {
    {10, 16},
    {11, 16},
};
#include "ht_enemy_animation.cpp.h"

security_guard::security_guard(ht::enemy::grade grade_val):
    enemy(ht::object::type::ENEMY, (int)ht::object::enemy_id::SECURITY_GUARD),
    _grade(grade_val),
    _stat(ht::enemy_stat::IDLE),
    _current_direction(ht::directions::DOWN),
    _pos(0,0),
    _speed(0),
    _rect_ptr(NULL),
    _sprite(bn::sprite_items::security_guard.create_sprite(0, 0))
{
    if(_grade == ht::enemy::grade::NORMAL) _speed = 38.0f;
    else if(_grade == ht::enemy::grade::HARD) _speed = 50.0f;
    else if(_grade == ht::enemy::grade::INSANE) _speed = 58.0f;

    // set collider
    bn::fixed_rect enemy_rect(0,0,4,18);
    _rect_ptr = &collision_manager::create_rect_body(collision_manager::body_type::DYNAMIC, enemy_rect);
    _rect_ptr->set_user_data((void*)this);
    _rect_ptr->set_collision_callback(collision_handler_func);
    
    // set ai
    _ai_stat.time = 0;
    _ai_stat.scenario_index = 0;
    _ai_stat.current_act_stat = ai_action_stat::INIT;

    // set sprite
    _set_direction();
    _init_animation();
}

security_guard::security_guard(ht::enemy::grade grade_val,
                               bn::fixed_point& pos_ref,
                               struct ai_scenario_t* ai_list, int size):
    security_guard(grade_val)
{
    set_position(pos_ref);
    set_ai_scenario(ai_list, size);
}

void security_guard::update() {
    // get collider position
    const bn::fixed_rect& enemy_rect = _rect_ptr->rect();
    bn::fixed_point new_pos(enemy_rect.x(), enemy_rect.y());

    // ai update
    if (_ai_stat.current_act_stat == ai_action_stat::INIT) {
        _ai_stat.current_act = _ai_scenario[0].ai_act;
        _ai_stat.param = _ai_scenario[0].param;
        _ai_stat.current_act_stat = ai_action_stat::START;    
    }
    
    if (_ai_stat.current_act_stat == ai_action_stat::START) {
        _ai_stat.time += 0.016f;
        bool vel_zero_flg = false;

        switch (_ai_stat.current_act) {
        case ai_action_type::WAIT:
            if (_ai_stat.time >= *((bn::fixed*)_ai_stat.param)) {
                _ai_stat.current_act_stat = ai_action_stat::DONE;
            }
            break;
        case ai_action_type::MOVE_TO:
            _update_move_to(new_pos, vel_zero_flg);
            break;
        default:
            BN_ERROR("Invalid ai_action_type: ", (int)_ai_stat.current_act);
            break;
        }

        if (vel_zero_flg) {
            ht::collision_manager::velocity vel_zero(0.0f, 0.0f);
            _rect_ptr->set_velocity(vel_zero);
            _ai_stat.current_act_stat = ai_action_stat::DONE;
            _stat = ht::enemy_stat::IDLE;
            _set_direction();
        }
    }

    if (_ai_stat.current_act_stat == ai_action_stat::DONE) {
        // setup next scenario
        if ((_ai_stat.scenario_index + 1) < _ai_scenario.size()) {
            _ai_stat.scenario_index += 1;
        } else {
            _ai_stat.scenario_index = 0;
        }
        _ai_stat.time = 0;
        _ai_stat.current_act = _ai_scenario[_ai_stat.scenario_index].ai_act;
        _ai_stat.param = _ai_scenario[_ai_stat.scenario_index].param;
        _ai_stat.current_act_stat = ai_action_stat::START;
    }

    if (_pos != new_pos) {
       _pos = new_pos;
       _sprite.set_position(_pos);
    }

    if (_stat == ht::enemy_stat::RUN) {
        _update_animation();
    }
}

void security_guard::set_position(bn::fixed_point& pos) {
    _rect_ptr->set_position(pos);
}

void security_guard::set_ai_scenario(struct ai_scenario_t* ai_list, int size) {
    _ai_scenario.clear();
    for (int i = 0; i < size; ++i) {
        _ai_scenario.push_back(ai_list[i]);
    }
}

void security_guard::_set_tiles(int index) {
    switch (_grade) {
    case ht::enemy::grade::NORMAL:
        _sprite.set_tiles(
            bn::sprite_items::security_guard.tiles_item().create_tiles(index));
        break;
    case ht::enemy::grade::HARD:
        _sprite.set_tiles(
            bn::sprite_items::security_guard.tiles_item().create_tiles(index));
        _sprite.set_palette(
            bn::sprite_items::security_guard_hard.palette_item());
        break;
    case ht::enemy::grade::INSANE:
        _sprite.set_tiles(
            bn::sprite_items::security_guard.tiles_item().create_tiles(index));
        _sprite.set_palette(
            bn::sprite_items::security_guard_insane.palette_item());
        break;
    default:
        BN_ERROR("Invalid _grade: ", (int)_grade);
        break;
    }
}

void security_guard::collision_handler_func(ht::collision_manager::rect_body* body_a, ht::collision_manager::rect_body* body_b) {
#if 1
    BN_ASSERT(body_a != NULL, "security_guard::collision_handler_func: body_a == NULL");
    BN_ASSERT(body_b != NULL, "security_guard::collision_handler_func: body_b == NULL");
#else
    ht::object* object_a = (ht::object*)body_a->user_data();
    ht::object* object_b = (ht::object*)body_b->user_data();

    if (object_a->get_type() == ht::object::type::ENEMY) {
        //BN_LOG("security_guard::collision_handler_func(): ", object_b->get_type());
    } else {
        //BN_LOG("security_guard::collision_handler_func(): ", object_a->get_type());
    }
#endif
}

}
