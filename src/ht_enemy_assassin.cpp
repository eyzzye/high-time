#include "ht_enemy_assassin.h"

#include "ht_time_manager.h"

extern bn::fixed_point g_hero_pos;

namespace ht {

#define HT_THIS_CLASS_NAME assassin
#include "ht_enemy_ai_trace.cpp.h"

static const int enemy_blink_target_time = 10;

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

assassin::assassin(ht::enemy::grade grade_val):
    enemy(ht::object::type::ENEMY, (int)ht::object::enemy_id::ASSASSIN),
    _grade(grade_val),
    _stat(ht::enemy_stat::IDLE),
    _current_direction(ht::directions::DOWN),
    _pos(0,0),
    _speed(0),
    _rect_ptr(NULL),
    _trace(NULL),
    _sprite(bn::sprite_items::assassin.create_sprite(0, 0)),
    _target_sprite(nullptr),
    _blink_target_time(0),
    _target_enable(false)
{
    if(_grade == ht::enemy::grade::NORMAL) _speed = 38.0f;
    else if(_grade == ht::enemy::grade::HARD) _speed = 50.0f;
    else if(_grade == ht::enemy::grade::INSANE) _speed = 72.0f;

    // set target sprite
    _target_sprite.reset(new bn::sprite_ptr(bn::sprite_items::mark_tiles.create_sprite(0, 0, 1)));
    _target_sprite->set_visible(false);

    // set collider
    bn::fixed_rect enemy_rect(0,0,4,18);
    _rect_ptr = &collision_manager::create_rect_body(collision_manager::body_type::DYNAMIC, enemy_rect);
    _rect_ptr->set_user_data((void*)this);
    _rect_ptr->set_collision_callback(collision_handler_func);
    
    // set ai
    _ai_stat.time = 0;
    _ai_stat.scenario_index = 0;
    _ai_stat.current_act_stat = ai_action_stat::INIT;
    
    // trace
    _trace = &ht::trace_manager::assigne_trace_data();

    // set sprite
    _set_direction();
    _init_animation();
}

assassin::assassin(ht::enemy::grade grade_val,
                   bn::fixed_point& pos_ref,
                   struct ai_scenario_t* ai_list, int size):
    assassin(grade_val)
{
    set_position(pos_ref);
    set_ai_scenario(ai_list, size);
}

static bn::fixed assassin_wait_time = 10.0f;
static bn::fixed assassin_move_time = 30.0f;
void assassin::update() {
    // get collider position
    const bn::fixed_rect& enemy_rect = _rect_ptr->rect();
    bn::fixed_point new_pos(enemy_rect.x(), enemy_rect.y());

    // ai update
    if (_ai_stat.current_act_stat == ai_action_stat::INIT) {
        _ai_stat.current_act = ai_action_type::WAIT;
        _ai_stat.param = &assassin_wait_time;
        _ai_stat.current_act_stat = ai_action_stat::START;    
    }
    
    if (_ai_stat.current_act_stat == ai_action_stat::START) {
        _ai_stat.time += 0.016f;
        bool vel_zero_flg = false;

        switch (_ai_stat.current_act) {
        case ai_action_type::WAIT:
            if (ht::time_manager::get_enemy_stat() != ht::time_manager::enemy_stat::IDLE) {
                _ai_stat.current_act_stat = ai_action_stat::DONE;
            }
            break;
        case ai_action_type::MOVE_TO:
        case ai_action_type::TRACE:
            _update_trace(new_pos, vel_zero_flg);
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
        bool set_next_senario = false;
        if (_ai_stat.current_act == ai_action_type::WAIT) {
            // get_trace_route
            ht::trace_manager::get_trace_route(*_trace, new_pos);

            if (_trace->size() > 0) {
                _ai_stat.scenario_index = 0;
                _ai_stat.current_act = ai_action_type::MOVE_TO;
                _ai_stat.param = (void*)&(*_trace)[0].pos;
                _ai_stat.time = 0;
                _ai_stat.current_act_stat = ai_action_stat::START;
                set_next_senario = true;

                _target_sprite->set_position((*_trace)[0].pos);
                _set_target_enable(true);
            }
        }
        else if (_ai_stat.current_act == ai_action_type::MOVE_TO) {
            if (ht::time_manager::get_enemy_stat() != ht::time_manager::enemy_stat::ACTIVE) {
                // WAIT
                //set_next_senario = false;
                _set_target_enable(false);
            }
            // continue current trace
            else if ((_ai_stat.scenario_index + 1) < _trace->size()) {
                _ai_stat.scenario_index += 1;

                _ai_stat.current_act = ai_action_type::MOVE_TO;
                _ai_stat.param = (void*)&(*_trace)[_ai_stat.scenario_index].pos;
                _ai_stat.time = 0;
                _ai_stat.current_act_stat = ai_action_stat::START;
                set_next_senario = true;

                _target_sprite->set_position((*_trace)[_ai_stat.scenario_index].pos);
                _set_target_enable(true);
            } else {
                // trace end
                ht::collision_manager::velocity vel(0.0f, 0.0f);
                _rect_ptr->set_velocity(vel);
                _stat = ht::enemy_stat::IDLE;
                _set_direction();
                _set_target_enable(false);

                // get_trace_route
                ht::trace_manager::get_trace_route(*_trace, new_pos);

                if (_trace->size() > 0) {
                    _ai_stat.scenario_index = 0;
                    _ai_stat.param = (void*)&(*_trace)[0].pos;
                    _ai_stat.time = 0;
                    _ai_stat.current_act_stat = ai_action_stat::START;

                    _target_sprite->set_position((*_trace)[0].pos);
                    _set_target_enable(true);
                }
                set_next_senario = true;
            }
        }

        if (set_next_senario == false) {
            ht::collision_manager::velocity vel(0.0f, 0.0f);
            _rect_ptr->set_velocity(vel);
            _stat = ht::enemy_stat::IDLE;
            _set_direction();
            _set_target_enable(false);

            _ai_stat.current_act = ai_action_type::WAIT;
            _ai_stat.param = &assassin_wait_time;
            _ai_stat.time = 0;
            _ai_stat.current_act_stat = ai_action_stat::START;
        }
    }

    if (_pos != new_pos) {
       _pos = new_pos;
       _sprite.set_position(_pos);
    }

    if (_stat == ht::enemy_stat::RUN) {
        _update_animation();
    }

    // blink target mark
    if ((_target_sprite != nullptr) && _target_enable) {
        _blink_target_time += 1;
        if (_blink_target_time > enemy_blink_target_time) {
            _target_sprite->set_visible(!_target_sprite->visible());
            _blink_target_time = 0;
        }
    }
}

void assassin::set_position(bn::fixed_point& pos) {
    _rect_ptr->set_position(pos);
}

void assassin::set_ai_scenario(struct ai_scenario_t* ai_list, int size) {
    _ai_scenario.clear();
    for (int i = 0; i < size; ++i) {
        _ai_scenario.push_back(ai_list[i]);
    }
}

void assassin::_set_tiles(int index) {
    _sprite.set_tiles(
        bn::sprite_items::assassin.tiles_item().create_tiles(index));
}

void assassin::_set_target_enable(bool on) {
    if (_target_enable == on) return;
    if (on == false) _target_sprite->set_visible(false);
    _target_enable = on;
}

void assassin::collision_handler_func(ht::collision_manager::rect_body* body_a, ht::collision_manager::rect_body* body_b) {
#if 1
    BN_ASSERT(body_a != NULL, "assassin::collision_handler_func: body_a == NULL");
    BN_ASSERT(body_b != NULL, "assassin::collision_handler_func: body_b == NULL");
#else
    ht::object* object_a = (ht::object*)body_a->user_data();
    ht::object* object_b = (ht::object*)body_b->user_data();

    if (object_a->get_type() == ht::object::type::ENEMY) {
        //BN_LOG("assassin::collision_handler_func(): ", object_b->get_type());
    } else {
        //BN_LOG("assassin::collision_handler_func(): ", object_a->get_type());
    }
#endif
}

}
