#ifndef HT_TIME_MANAGER_H
#define HT_TIME_MANAGER_H

#include "bn_timer.h"

#include "ht_common.h"

namespace ht::time_manager {

enum class stat {
    INIT,
    ACTIVE,
    PAUSE,
};

enum class enemy_stat {
    NONE,
    IDLE,
    ACTIVE,
};

// extern functions
void init();
void update();
void pause();
void start();
int get_time();
ht::time_manager::enemy_stat get_enemy_stat();

}

#endif

