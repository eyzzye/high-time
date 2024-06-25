#include "ht_stage3.h"
#include "ht_stage3_tiles.h"

namespace ht {

// enemy
static bn::fixed wait_time(2.0f);

#include "ht_stage3_0.cpp.h"
#include "ht_stage3_1.cpp.h"
#include "ht_stage3_2.cpp.h"
#include "ht_stage3_3.cpp.h"

void stage3::update() {
    if (_enemy_list.size() > 0) {
        for (int i = 0; i < _enemy_list.size(); i++) {
            _enemy_list[i]->update();
        }
    }
}

bn::regular_bg_ptr stage3::create_intro_bg() {
    return bn::regular_bg_items::stage3_intro.create_bg(0, 0);
}

const char* stage3::get_intro_message() {
    return "It's better to have";
}

bn::regular_bg_ptr stage3::create_outro_bg() {
    return bn::regular_bg_items::stage3_outro.create_bg(0, 0);
}

const char* stage3::get_outro_message() {
    return "There's nothing to fear anymore";
}

//
// must have one each floor.
//
struct array_t<ht::terrain_init_data_t>* stage3::get_terrain_init_list()
{
    if (_floor_index == 0) return &stage3_0_data.terrain_init_list;
    if (_floor_index == 1) return &stage3_1_data.terrain_init_list;
    if (_floor_index == 2) return &stage3_2_data.terrain_init_list;
    if (_floor_index == 3) return &stage3_3_data.terrain_init_list;

    return &stage3_0_data.terrain_init_list;
}

bn::regular_bg_ptr stage3::create_terrain() {
    if (_floor_index == 0) return bn::regular_bg_items::stage3_0.create_bg(0, 0);
    if (_floor_index == 1) return bn::regular_bg_items::stage3_1.create_bg(0, 0);
    if (_floor_index == 2) return bn::regular_bg_items::stage3_2.create_bg(0, 0);
    if (_floor_index == 3) return bn::regular_bg_items::stage3_3.create_bg(0, 0);

    return bn::regular_bg_items::stage3_0.create_bg(0, 0);
}

const bn::regular_bg_item& stage3::get_bg_map_tiles() {
    return bn::regular_bg_items::stage3_bg_tiles;
}

struct array_t<struct ht::bg_map_manager::init_data_t>* stage3::get_bg_map_init_list() {
    if (_floor_index == 0) return &stage3_0_data.bg_map_init_list;
    if (_floor_index == 1) return &stage3_1_data.bg_map_init_list;
    if (_floor_index == 2) return &stage3_2_data.bg_map_init_list;
    if (_floor_index == 3) return &stage3_3_data.bg_map_init_list;

    return &stage3_0_data.bg_map_init_list;
}

void stage3::init_trace_manager() {
    ht::trace_manager::init();

    if (_floor_index == 0) {
        ht::trace_manager::init_area(&stage3_0_data.area_init_list);
        ht::trace_manager::init_connections(&stage3_0_data.connection_init_list);
    }
    if (_floor_index == 1) {
        ht::trace_manager::init_area(&stage3_1_data.area_init_list);
        ht::trace_manager::init_connections(&stage3_1_data.connection_init_list);
    }
    if (_floor_index == 2) {
        ht::trace_manager::init_area(&stage3_2_data.area_init_list);
        ht::trace_manager::init_connections(&stage3_2_data.connection_init_list);
    }
    if (_floor_index == 3) {
        ht::trace_manager::init_area(&stage3_3_data.area_init_list);
        ht::trace_manager::init_connections(&stage3_3_data.connection_init_list);
    }
}


//
// not always exist
//
bool stage3::get_enable(int type, int id) {
    if (_floor_index == 0) return get_stage3_0_enable(type, id);
    if (_floor_index == 1) return get_stage3_1_enable(type, id);
    if (_floor_index == 2) return get_stage3_2_enable(type, id);
    if (_floor_index == 3) return get_stage3_3_enable(type, id);
    return false;
}

bn::fixed_point stage3::get_hero_start_pos() {
    if (_floor_index == 0) {
        bn::fixed_point pos(-8,184);
        return pos;
    }

    bn::fixed_point default_pos(0,0);
    return default_pos;
}

bn::fixed_rect stage3::get_goal_region() {
    if (_floor_index == 3) {
        bn::fixed_rect rect(0.0,-144.0,32.0,32.0);
        return rect;
    }

    bn::fixed_rect default_rect(0,0,0,0);
    return default_rect;
}

struct array_t<struct ht::stairs_init_data_t>* stage3::get_stairs_init_list() {
    if (_floor_index == 0) return &stage3_0_data.stairs_init_list;
    if (_floor_index == 1) return &stage3_1_data.stairs_init_list;
    if (_floor_index == 2) return &stage3_2_data.stairs_init_list;
    if (_floor_index == 3) return &stage3_3_data.stairs_init_list;

    return &stage3_0_data.stairs_init_list;
}

struct array_t<struct ht::teleport_init_data_t>* stage3::get_teleport_init_list() {
    if (_floor_index == 0) return &stage3_0_data.teleport_init_list;
    if (_floor_index == 1) return &stage3_1_data.teleport_init_list;
    if (_floor_index == 2) return &stage3_2_data.teleport_init_list;
    if (_floor_index == 3) return &stage3_3_data.teleport_init_list;

    return &stage3_0_data.teleport_init_list;
}

struct array_t<struct ht::gate_init_data_t>* stage3::get_gate_init_list() {
    if (_floor_index == 0) return &stage3_0_data.gate_init_list;
    if (_floor_index == 1) return &stage3_1_data.gate_init_list;
    if (_floor_index == 2) return &stage3_2_data.gate_init_list;
    if (_floor_index == 3) return &stage3_3_data.gate_init_list;

    return &stage3_0_data.gate_init_list;
}

int stage3::get_gate_tile_index(ht::directions direction,
                                ht::gate_actions open_close,
                                int index)
{
    return _get_gate_tile_index((int)direction, (int)open_close, index);
}

struct array_t<struct ht::item_key_init_data_t>* stage3::get_item_key_init_list() {
    if (_floor_index == 0) return &stage3_0_data.item_key_init_list;
    if (_floor_index == 1) return &stage3_1_data.item_key_init_list;
    if (_floor_index == 2) return &stage3_2_data.item_key_init_list;
    if (_floor_index == 3) return &stage3_3_data.item_key_init_list;

    return &stage3_0_data.item_key_init_list;
}

void stage3::create_enemy() {
    if (_floor_index == 0) { _stage3_0_create_enemy(); }
    if (_floor_index == 1) { _stage3_1_create_enemy(); }
    if (_floor_index == 2) { _stage3_2_create_enemy(); }
    if (_floor_index == 3) { _stage3_3_create_enemy(); }
}

void stage3::destroy_enemy() {
    _enemy_list.clear();
    _e_security_guard.clear();
    _e_dog.clear();
    _e_chaser.clear();
}

void stage3::set_camera(bn::camera_ptr& camera) {
    if (_enemy_list.size() > 0) {
        for (int i = 0; i < _enemy_list.size(); i++) {
            _enemy_list[i]->set_camera(camera);
        }
    }
}

void stage3::play_music() {
    bn::music_items::music003.play(0.5);
}

}

