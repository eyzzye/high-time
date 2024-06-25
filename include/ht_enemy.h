#ifndef HT_ENEMY_H
#define HT_ENEMY_H

#include "bn_fixed.h"
#include "bn_camera_ptr.h"

namespace ht {

enum class enemy_stat {
    IDLE,
    RUN
};

enum class ai_action_type {
    WAIT,
    MOVE_TO,
    TRACE
};

enum class ai_action_stat {
    INIT,
    START,
    PAUSE,
    DONE
};

struct ai_scenario_t {
   ai_action_type ai_act;
   void* param; 
};

struct ai_stat_t {
   bn::fixed time;
   int scenario_index;
   ai_action_type current_act;
   ai_action_stat current_act_stat;
   void* param;
};

struct animation_frame_data_t {
    int tile_index;
    int wait_updates;
};

struct animation_data_t {
    int list_index;
    int tile_index;
    int wait_time;
    struct animation_frame_data_t* frame_data;
    int frame_data_size;
};

class enemy : public object {
public:
    enum class grade {
        NORMAL = 1,
        HARD,
        INSANE
    };

    enemy(ht::object::type type_val):
        object(type_val)
    {}

    enemy(ht::object::type type_val, int id):
        object(type_val, id)
    {}

    virtual void update() = 0;
    virtual void set_camera(bn::camera_ptr& camera) = 0;
};

}

#endif
