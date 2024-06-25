#include "ht_hero.h"

#include "bn_keypad.h"
#include "../../../butano/hw/include/bn_hw_keypad.h"

#include "ht_trace_manager.h"
#include "ht_stairs.h"
#include "ht_teleport.h"
#include "ht_gate.h"
#include "ht_item_key.h"

extern bn::fixed g_sound_effect_wait;
extern int g_hero_item_count[(int)ht::object::item_id::ITEM_MAX];
extern bn::fixed_point g_hero_pos;
extern ht::game_result g_game_result;
extern int g_game_next_floor;
extern bn::fixed_point g_game_next_floor_pos;
extern ht::gate_actions g_game_gate_action;
extern int g_game_gate_list_index;
extern bn::fixed_point* g_game_gate_bg_map_pos;
extern ht::directions g_game_gate_direction;
extern ht::object::item_stat g_game_item_key_stat;
extern int g_game_item_key_list_index;

namespace ht {

hero::hero():
    object(ht::object::type::HERO),
    _stat(ht::hero::stat::IDLE),
    _current_direction(ht::directions::DOWN),
    _pos(0,0),
    _speed(0),
    _rect_ptr(NULL),
    _sprite(bn::sprite_items::hero_running.create_sprite(0, 0))
{
    g_hero_pos = bn::fixed_point(0,0);
}

void hero::init() {
    _speed = 40.0f;

    // set rect body
    bn::fixed_rect hero_rect(0,0,4,18);
    _rect_ptr = &collision_manager::create_rect_body(collision_manager::body_type::DYNAMIC, hero_rect);
    _rect_ptr->set_user_data((void*)this);
    _rect_ptr->set_collision_callback(collision_handler_func);

    // set sprite
    _stat = ht::hero::stat::IDLE;
    _current_direction = ht::directions::DOWN;
    _set_direction();
}

void hero::key_event() {
    unsigned int all_directions = ((unsigned int)bn::keypad::key_type::UP) |
                                  ((unsigned int)bn::keypad::key_type::DOWN) |
                                  ((unsigned int)bn::keypad::key_type::RIGHT) |
                                  ((unsigned int)bn::keypad::key_type::LEFT);
    unsigned current_keys = bn::hw::keypad::get();

    if (current_keys & all_directions) {
        // update positon
        bool dirty = false;
        ht::collision_manager::velocity vel(0,0);
        if (bn::keypad::held(bn::keypad::key_type::LEFT)) {
            vel.set_vx(-_speed);
            dirty = true;
        }
        if (bn::keypad::held(bn::keypad::key_type::RIGHT)) {
            vel.set_vx(_speed);
            dirty = true;
        }
        if (bn::keypad::held(bn::keypad::key_type::UP)) {
            vel.set_vy(-_speed);
            dirty = true;
        }
        if (bn::keypad::held(bn::keypad::key_type::DOWN)) {
            vel.set_vy(_speed);
            dirty = true;
        }
        if (dirty) {
            _rect_ptr->set_velocity(vel);
        }

        // set idle sprite
        _stat = ht::hero::stat::RUN;
        _set_run();
    }

    if (bn::keypad::released(bn::keypad::key_type::UP)    ||
        bn::keypad::released(bn::keypad::key_type::DOWN)  ||
        bn::keypad::released(bn::keypad::key_type::RIGHT) ||
        bn::keypad::released(bn::keypad::key_type::LEFT))
    {
        if (!(current_keys & all_directions)) {
            // stop body
            _rect_ptr->set_velocity(ht::collision_manager::velocity(0,0));

            // set idle sprite
            _stat = ht::hero::stat::IDLE;
            _set_direction();
        }
        else {
            _change_run();
        }
    }
}

void hero::update() {
    // get position
    const bn::fixed_rect& hero_rect = _rect_ptr->rect();
    bn::fixed_point new_pos(hero_rect.x(), hero_rect.y());

    if (_pos != new_pos) {
       _pos = new_pos;
       g_hero_pos = _pos;
       ht::trace_manager::update_trace_point(g_hero_pos);

       // set sprite position
       _sprite.set_position(_pos);
    }

    if (_stat == ht::hero::stat::RUN) {
        _action[(int)_current_direction].update();
    }
}

void hero::set_position(const bn::fixed_point& pos) {
    _rect_ptr->set_position(pos);
}

void hero::_set_run() {
    if (bn::keypad::pressed(bn::keypad::key_type::LEFT)) {
        _current_direction = ht::directions::LEFT;
    }
    if (bn::keypad::pressed(bn::keypad::key_type::RIGHT)) {
        _current_direction = ht::directions::RIGHT;
    }
    if (bn::keypad::pressed(bn::keypad::key_type::UP)) {
        _current_direction = ht::directions::UP;
    }
    if (bn::keypad::pressed(bn::keypad::key_type::DOWN)) {
        _current_direction = ht::directions::DOWN;
    }
}

void hero::_change_run() {
    if (bn::keypad::held(bn::keypad::key_type::LEFT)) {
        if (_current_direction != ht::directions::LEFT) {
            _current_direction = ht::directions::LEFT;
        }
    }
    if (bn::keypad::held(bn::keypad::key_type::RIGHT)) {
        if (_current_direction != ht::directions::RIGHT) {
            _current_direction = ht::directions::RIGHT;
        }
    }
    if (bn::keypad::held(bn::keypad::key_type::UP)) {
        if (_current_direction != ht::directions::UP) {
            _current_direction = ht::directions::UP;
        }
    }
    if (bn::keypad::held(bn::keypad::key_type::DOWN)) {
        if (_current_direction != ht::directions::DOWN) {
            _current_direction = ht::directions::DOWN;
        }
    }
}

void hero::_set_direction() {
    _sprite.set_tiles(_tiles_list[(int)_current_direction]);
}

void hero::collision_handler_func(ht::collision_manager::rect_body* body_a, ht::collision_manager::rect_body* body_b) {
    ht::object* object_a = (ht::object*)body_a->user_data();
    ht::object* object_b = (ht::object*)body_b->user_data();

    if (object_a->get_type() == ht::object::type::HERO) {
        switch (object_b->get_type()) {
        case ht::object::type::ENEMY:
            g_game_result = game_result::LOSE;
            break;
        case ht::object::type::EVENT:
            if (object_b->get_id() == (int)ht::object::event_id::GOAL) {
                g_game_result = game_result::WIN;
            }
            if (object_b->get_id() == (int)ht::object::event_id::STAIRS) {
                ht::stairs* stairs_obj = (ht::stairs*)object_b;
                g_game_next_floor = stairs_obj->get_next_floor();
                g_game_next_floor_pos = stairs_obj->get_next_floor_pos();
                bn::sound_items::footstep.play();
            }
            if (object_b->get_id() == (int)ht::object::event_id::TELEPORT) {
                ht::teleport* teleport_obj = (ht::teleport*)object_b;
                g_game_next_floor = teleport_obj->get_next_floor();
                g_game_next_floor_pos = teleport_obj->get_next_floor_pos();
                bn::sound_items::teleport.play();
            }
            if (object_b->get_id() == (int)ht::object::event_id::GATE) {
                ht::gate* gate_obj = (ht::gate*)object_b;
                if (g_hero_item_count[(int)ht::object::item_id::ITEM_KEY] > 0) {
                    gate_obj->open();
                    g_game_gate_list_index = gate_obj->get_list_index();
                    g_game_gate_bg_map_pos = gate_obj->get_bg_map_pos();
                    g_game_gate_direction = gate_obj->get_direction();
                    g_game_gate_action = ht::gate_actions::OPEN;
                    bn::sound_items::open_gate.play();

                    g_hero_item_count[(int)ht::object::item_id::ITEM_KEY] -= 1;
                }
                else {
                    if (g_sound_effect_wait <= 0) {
                        bn::sound_items::beep.play();
                        g_sound_effect_wait = 0.5f; // 0.5[sec]
                    }
                }
            }
            break;
        case ht::object::type::ITEM:
            if (object_b->get_id() == (int)ht::object::item_id::ITEM_KEY) {
                ht::item_key* item_key_obj = (ht::item_key*)object_b;
                item_key_obj->set_enable(false);
                g_game_item_key_list_index = item_key_obj->get_list_index();
                g_game_item_key_stat = ht::object::item_stat::DISABLE;
                bn::sound_items::item_key.play();

                g_hero_item_count[(int)ht::object::item_id::ITEM_KEY] += 1;
            }
            break;
        case ht::object::type::TERRAIN:
        default:
            break;
        }
    }
}

}

