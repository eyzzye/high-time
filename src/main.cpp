#include "bn_core.h"
#include "bn_fixed.h"
#include "bn_random.h"

#include "ht_common.h"
#include "ht_score.h"
#include "ht_scene.h"
#include "ht_scene_topmenu.h"
#include "ht_scene_game.h"
#include "ht_scene_ending.h"

//
// global variables
//
ht::scene::type next_scene = ht::scene::type::NONE;
bn::fixed g_sound_effect_wait = 0;

// hero stat
ht::score g_score;
int g_hero_item_count[(int)ht::object::item_id::ITEM_MAX];
bn::fixed_point g_hero_pos(0,0);

// random generator
bn::random g_random;

// scene_game
ht::game* g_game_ptr = NULL;
ht::game_result g_game_result = ht::game_result::YET;

int g_game_next_floor = HT_UNINITIALIZED;
bn::fixed_point g_game_next_floor_pos(0,0);

ht::gate_actions g_game_gate_action = ht::gate_actions::NONE;
int g_game_gate_list_index = HT_UNINITIALIZED;
bn::fixed_point* g_game_gate_bg_map_pos = NULL;
ht::directions g_game_gate_direction = ht::directions::DOWN;

ht::object::item_stat g_game_item_key_stat = ht::object::item_stat::NONE;
int g_game_item_key_list_index = HT_UNINITIALIZED;

int main()
{
    bn::unique_ptr<ht::scene> current_scene;
    const bn::fixed change_scene_wait = 0.5f;
    bn::fixed g_wait_time = 0.0f;

    // init butano engine
    bn::core::init();
    
    current_scene.reset(new ht::topmenu());
    //current_scene.reset(new ht::ending());

    while(true)
    {
        if (current_scene->get_stat() == ht::scene::stat::ACTIVE) {
            current_scene->update();
        }

        if (next_scene != ht::scene::type::NONE) {
            bool result = false;

            // finish current_scene
            current_scene.reset();

            // wait a little time
            while (g_wait_time < change_scene_wait) {
                bn::core::update();
                g_wait_time += 0.016f;
            }
            g_wait_time = 0.0f; // clear

            switch (next_scene) {
            case ht::scene::type::TOPMENU:
                current_scene.reset(new ht::topmenu());
                result = true;
                break;
            case ht::scene::type::GAME:
                current_scene.reset(new ht::game());
                result = true;
                break;
            case ht::scene::type::ENDING:
                current_scene.reset(new ht::ending());
                result = true;
                break;
            default:
                BN_ERROR("main(): Invalid next_scene ", (int)next_scene);
                break;
            }

            if (result && (current_scene->get_stat() == ht::scene::stat::ACTIVE)) {
                next_scene = ht::scene::type::NONE;
            }
            else {
                BN_ERROR("main(): Invalid next_scene");
                next_scene = ht::scene::type::NONE;
            }
        }
    }
}

