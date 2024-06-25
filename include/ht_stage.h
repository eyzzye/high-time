#ifndef HT_STAGE_H
#define HT_STAGE_H

#include "bn_fixed.h"
#include "bn_regular_bg_ptr.h"
#include "bn_camera_ptr.h"

#include "ht_common.h"
#include "ht_array_t.h"
#include "ht_terrain.h"
#include "ht_bg_map_manager.h"
#include "ht_trace_manager.h"
#include "ht_stairs.h"
#include "ht_teleport.h"
#include "ht_gate.h"
#include "ht_item_key.h"

namespace ht {

class stage {
public:
    stage():
        _floor_index(0)
    {
        // set _gate_stat[][]
        for (int f_idx = 0; f_idx < HT_FLOOR_MAX; f_idx++) {
            for (int g_idx = 0; g_idx < HT_GATE_MAX; g_idx++) {
                _gate_stat[f_idx][g_idx] = ht::gate_actions::CLOSE;
            }
        }

        // set _item_key_stat[][]
        for (int f_idx = 0; f_idx < HT_FLOOR_MAX; f_idx++) {
            for (int i_idx = 0; i_idx < HT_ITEM_KEY_MAX; i_idx++) {
                _item_key_stat[f_idx][i_idx] = ht::object::item_stat::ENABLE;
            }
        }
    }

    virtual ~stage() = default;
    virtual void update() = 0;

    virtual bn::regular_bg_ptr create_intro_bg() = 0;
    virtual const char* get_intro_message() = 0;
    virtual bn::regular_bg_ptr create_outro_bg() = 0;
    virtual const char* get_outro_message() = 0;
    virtual struct array_t<ht::terrain_init_data_t>* get_terrain_init_list() = 0;
    virtual bn::regular_bg_ptr create_terrain() = 0;
    virtual const bn::regular_bg_item& get_bg_map_tiles() = 0;
    virtual struct array_t<struct ht::bg_map_manager::init_data_t>* get_bg_map_init_list() = 0;
    virtual void init_trace_manager() = 0;

    virtual bool get_enable(int type, int id=0) = 0;
    virtual bn::fixed_point get_hero_start_pos() = 0;
    virtual bn::fixed_rect get_goal_region() = 0;
    virtual struct array_t<struct ht::stairs_init_data_t>* get_stairs_init_list() = 0;
    virtual struct array_t<struct ht::teleport_init_data_t>* get_teleport_init_list() = 0;
    virtual struct array_t<struct ht::gate_init_data_t>* get_gate_init_list() = 0;
    virtual int get_gate_tile_index(ht::directions direction,
                                    ht::gate_actions open_close,
                                    int index) = 0;
    virtual struct array_t<struct ht::item_key_init_data_t>* get_item_key_init_list() = 0;
    virtual void create_enemy() = 0;
    virtual void destroy_enemy() = 0;
    virtual void set_camera(bn::camera_ptr& camera) = 0;
    virtual void play_music() = 0;

    void set_floor_index(int index) { _floor_index = index; }

    ht::gate_actions get_gate_stat(int gate_list_index) {
        return _gate_stat[_floor_index][gate_list_index];
    }

    void set_gate_stat(int gate_list_index, ht::gate_actions gate_act) {
        _gate_stat[_floor_index][gate_list_index] = gate_act;
    }

    ht::object::item_stat get_item_key_stat(int item_key_list_index) {
        return _item_key_stat[_floor_index][item_key_list_index];
    }
    void set_item_key_stat(int item_key_list_index, ht::object::item_stat item_stat) {
        _item_key_stat[_floor_index][item_key_list_index] = item_stat;
    }

protected:
    int _floor_index;
    ht::gate_actions _gate_stat[HT_FLOOR_MAX][HT_GATE_MAX];
    ht::object::item_stat _item_key_stat[HT_FLOOR_MAX][HT_ITEM_KEY_MAX];
};

}

#endif
