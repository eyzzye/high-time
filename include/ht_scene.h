#ifndef HT_SCENE_H
#define HT_SCENE_H

#include "ht_common.h"

namespace ht {

class scene {
public:
    enum class type {
        NONE,
        TOPMENU,
        GAME,
        ENDING
    };

    enum class stat {
        INIT,
        ACTIVE,
        DONE
    };

    scene(ht::scene::type type_val):
        _type(type_val),
        _stat(stat::INIT)
    {}

    virtual ~scene() = default;
    virtual void update() = 0;

    ht::scene::type get_type() { return _type; }
    ht::scene::stat get_stat() { return _stat; }
    void set_stat(ht::scene::stat stat_val) { _stat = stat_val; }
    
private:
    ht::scene::type _type;
    ht::scene::stat _stat;
};

}

#endif
