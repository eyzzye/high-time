#include "ht_time_manager.h"

namespace ht::time_manager {

class static_data {
public:
    ht::time_manager::stat current_stat;
    bn::timer timer;
    unsigned int total_ticks;
    unsigned int current_sec_time;

    ht::time_manager::enemy_stat enemy_stat;
    unsigned int enemy_stat_counter;
};

BN_DATA_EWRAM static_data data;
static const int enemy_stat_cnt_time = 30;

void init() {
    data.current_stat = ht::time_manager::stat::INIT;
    data.total_ticks = 0;
    data.current_sec_time = 0;

    data.enemy_stat = ht::time_manager::enemy_stat::IDLE;
    data.enemy_stat_counter = 0;

    data.timer.restart();
    data.current_stat = ht::time_manager::stat::ACTIVE;
}

void update() {
    if (data.current_stat == ht::time_manager::stat::ACTIVE) {
        data.total_ticks += data.timer.elapsed_ticks();
        if (data.total_ticks > 0x40000) {
            data.current_sec_time += 1;
            data.total_ticks -= 0x40000;

            // set enemy_stat
            data.enemy_stat_counter += 1;
            if (data.enemy_stat_counter >= enemy_stat_cnt_time) {
                data.enemy_stat_counter = 0;
                if (data.enemy_stat == ht::time_manager::enemy_stat::IDLE) {
                    data.enemy_stat = ht::time_manager::enemy_stat::ACTIVE;
                }
                else {
                    data.enemy_stat = ht::time_manager::enemy_stat::IDLE;
                }
            }
        }
        data.timer.restart();
    }
}

void pause() {
    if (data.current_stat != ht::time_manager::stat::PAUSE) {
        data.current_stat = ht::time_manager::stat::PAUSE;
    }
}

void start() {
    if (data.current_stat != ht::time_manager::stat::ACTIVE) {
        data.timer.restart();
        data.current_stat = ht::time_manager::stat::ACTIVE;
    }
}

int get_time() {
    return int(data.current_sec_time);
}

ht::time_manager::enemy_stat get_enemy_stat() {
    return data.enemy_stat;
}

}

