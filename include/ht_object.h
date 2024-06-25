#ifndef HT_OBJECT_H
#define HT_OBJECT_H

#include "ht_common.h"

namespace ht {

class object {
public:
    enum class type {
        HERO,
        EVENT,
        ENEMY,
        ITEM,
        TERRAIN
    };

    enum class event_id {
        GOAL = 1,
        STAIRS,
        TELEPORT,
        GATE,
    };

    enum class enemy_id {
        SECURITY_GUARD = 1,
        DOG,
        CHASER,
        ASSASSIN,
    };

    enum class item_id {
        ITEM_KEY = 1,
        ITEM_MAX
    };

    enum class item_stat {
        NONE=0,
        ENABLE=1,
        DISABLE=2,
    };

    object(ht::object::type type_val):
        _type(type_val),
        _id(HT_UNINITIALIZED)
    {}

    object(ht::object::type type_val, int id):
        _type(type_val),
        _id(id)
    {}

    virtual ~object() = default;

    ht::object::type get_type() { return _type; }
    int get_id() { return _id; }

private:
    ht::object::type _type;
    int _id;
};

}

#endif
