#ifndef HT_STAGE2_H
#define HT_STAGE2_H

#include "bn_fixed.h"
#include "bn_regular_bg_ptr.h"
#include "bn_vector.h"

#include "bn_regular_bg_items_stage2_intro.h"
#include "bn_regular_bg_items_stage2_outro.h"
#include "bn_regular_bg_items_stage2_bg_tiles.h"
#include "bn_regular_bg_items_stage2_0.h"
#include "bn_regular_bg_items_stage2_1.h"
#include "bn_regular_bg_items_stage2_2.h"
#include "bn_music_items.h"

#include "ht_stage.h"
#include "ht_collision_manager.h"
#include "ht_enemy_security_guard.h"
#include "ht_enemy_dog.h"
#include "ht_enemy_chaser.h"

namespace ht {

class stage2 : public stage {
public:
    stage2():
        stage()
    {}

    ~stage2()
    {
        _enemy_list.clear();
        _e_security_guard.clear();
        _e_dog.clear();
        _e_chaser.clear();
    }

    void update();

    bn::regular_bg_ptr create_intro_bg();
    const char* get_intro_message();
    bn::regular_bg_ptr create_outro_bg();
    const char* get_outro_message();
    struct array_t<ht::terrain_init_data_t>* get_terrain_init_list();
    bn::regular_bg_ptr create_terrain();
    const bn::regular_bg_item& get_bg_map_tiles();
    struct array_t<struct ht::bg_map_manager::init_data_t>* get_bg_map_init_list();
    void init_trace_manager();

    bool get_enable(int type, int id=0);
    bn::fixed_point get_hero_start_pos();
    bn::fixed_rect get_goal_region();
    struct array_t<struct ht::stairs_init_data_t>* get_stairs_init_list() { return NULL; };
    struct array_t<struct ht::teleport_init_data_t>* get_teleport_init_list();
    struct array_t<struct ht::gate_init_data_t>* get_gate_init_list();
    int get_gate_tile_index(ht::directions direction,
                            ht::gate_actions open_close,
                            int index);
    struct array_t<struct ht::item_key_init_data_t>* get_item_key_init_list();
    void create_enemy();
    void destroy_enemy();
    void set_camera(bn::camera_ptr& camera);
    void play_music();

private:
    bn::vector<ht::enemy*, 32> _enemy_list;
    bn::vector<ht::security_guard, 16> _e_security_guard;
    bn::vector<ht::dog, 8> _e_dog;
    bn::vector<ht::chaser, 8> _e_chaser;

    void _stage2_0_create_enemy();
    void _stage2_1_create_enemy();
    void _stage2_2_create_enemy();
};

}

#endif
