#include "ht_stage2.h"
#include "ht_stage2_tiles.h"

namespace ht {

// enemy
static bn::fixed wait_time(2.0f);

#include "ht_stage2_0.cpp.h"
#include "ht_stage2_1.cpp.h"
#include "ht_stage2_2.cpp.h"

void stage2::update() {
    if (_enemy_list.size() > 0) {
        for (int i = 0; i < _enemy_list.size(); i++) {
            _enemy_list[i]->update();
        }
    }
}

bn::regular_bg_ptr stage2::create_intro_bg() {
    return bn::regular_bg_items::stage2_intro.create_bg(0, 0);
}

const char* stage2::get_intro_message() {
    return "Money for now.";
}

bn::regular_bg_ptr stage2::create_outro_bg() {
    return bn::regular_bg_items::stage2_outro.create_bg(0, 0);
}

const char* stage2::get_outro_message() {
    return "All you need is this.";
}

//
// must have one each floor.
//
struct array_t<ht::terrain_init_data_t>* stage2::get_terrain_init_list()
{
    if (_floor_index == 0) return &stage2_0_data.terrain_init_list;
    if (_floor_index == 1) return &stage2_1_data.terrain_init_list;
    if (_floor_index == 2) return &stage2_2_data.terrain_init_list;

    return &stage2_0_data.terrain_init_list;
}

bn::regular_bg_ptr stage2::create_terrain() {
    if (_floor_index == 0) return bn::regular_bg_items::stage2_0.create_bg(0, 0);
    if (_floor_index == 1) return bn::regular_bg_items::stage2_1.create_bg(0, 0);
    if (_floor_index == 2) return bn::regular_bg_items::stage2_2.create_bg(0, 0);

    return bn::regular_bg_items::stage2_0.create_bg(0, 0);
}

const bn::regular_bg_item& stage2::get_bg_map_tiles() {
    return bn::regular_bg_items::stage2_bg_tiles;
}

struct array_t<struct ht::bg_map_manager::init_data_t>* stage2::get_bg_map_init_list() {
    if (_floor_index == 0) return &stage2_0_data.bg_map_init_list;
    if (_floor_index == 1) return &stage2_1_data.bg_map_init_list;
    if (_floor_index == 2) return &stage2_2_data.bg_map_init_list;

    return &stage2_0_data.bg_map_init_list;
}

void stage2::init_trace_manager() {
    ht::trace_manager::init();

    if (_floor_index == 0) {
        ht::trace_manager::init_area(&stage2_0_data.area_init_list);
        ht::trace_manager::init_connections(&stage2_0_data.connection_init_list);
    }
    if (_floor_index == 1) {
        ht::trace_manager::init_area(&stage2_1_data.area_init_list);
        ht::trace_manager::init_connections(&stage2_1_data.connection_init_list);
    }
    if (_floor_index == 2) {
        ht::trace_manager::init_area(&stage2_2_data.area_init_list);
        ht::trace_manager::init_connections(&stage2_2_data.connection_init_list);
    }
}

//
// not always exist
//
bool stage2::get_enable(int type, int id) {
    if (_floor_index == 0) return get_stage2_0_enable(type, id);
    if (_floor_index == 1) return get_stage2_1_enable(type, id);
    if (_floor_index == 2) return get_stage2_2_enable(type, id);
    return false;
}

bn::fixed_point stage2::get_hero_start_pos() {
    if (_floor_index == 0) {
        bn::fixed_point pos(-200,216);
        return pos;
    }

    bn::fixed_point default_pos(0,0);
    return default_pos;
}

bn::fixed_rect stage2::get_goal_region() {
    if (_floor_index == 2) {
        bn::fixed_rect rect(0.0,-208.0,64.0,32.0);
        return rect;
    }

    bn::fixed_rect default_rect(0,0,0,0);
    return default_rect;
}

struct array_t<struct ht::teleport_init_data_t>* stage2::get_teleport_init_list() {
    if (_floor_index == 0) return &stage2_0_data.teleport_init_list;
    if (_floor_index == 1) return &stage2_1_data.teleport_init_list;
    if (_floor_index == 2) return &stage2_2_data.teleport_init_list;

    return &stage2_0_data.teleport_init_list;
}

struct array_t<struct ht::gate_init_data_t>* stage2::get_gate_init_list() {
    if (_floor_index == 0) return &stage2_0_data.gate_init_list;
    if (_floor_index == 1) return &stage2_1_data.gate_init_list;
    if (_floor_index == 2) return &stage2_2_data.gate_init_list;

    return &stage2_0_data.gate_init_list;
}

int stage2::get_gate_tile_index(ht::directions direction,
                                ht::gate_actions open_close,
                                int index)
{
    return _get_gate_tile_index((int)direction, (int)open_close, index);
}

struct array_t<struct ht::item_key_init_data_t>* stage2::get_item_key_init_list() {
    if (_floor_index == 0) return &stage2_0_data.item_key_init_list;
    if (_floor_index == 1) return &stage2_1_data.item_key_init_list;
    if (_floor_index == 2) return &stage2_2_data.item_key_init_list;

    return &stage2_0_data.item_key_init_list;
}

void stage2::create_enemy() {
    if (_floor_index == 0) { _stage2_0_create_enemy(); }
    if (_floor_index == 1) { _stage2_1_create_enemy(); }
    if (_floor_index == 2) { _stage2_2_create_enemy(); }
}

void stage2::destroy_enemy() {
    _enemy_list.clear();
    _e_security_guard.clear();
    _e_dog.clear();
    _e_chaser.clear();
}

void stage2::set_camera(bn::camera_ptr& camera) {
    if (_enemy_list.size() > 0) {
        for (int i = 0; i < _enemy_list.size(); i++) {
            _enemy_list[i]->set_camera(camera);
        }
    }
}

void stage2::play_music() {
    bn::music_items::music002.play(0.5);
}

}

