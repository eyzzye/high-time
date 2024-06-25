#ifndef HT_STAIRS_H
#define HT_STAIRS_H

#include "ht_common.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

struct stairs_init_data_t {
    bn::fixed_point pos;
    int next_floor;
    bn::fixed_point next_floor_pos;
};

class stairs : public object {
public:
    stairs():
        object(ht::object::type::EVENT, (int)ht::object::event_id::STAIRS),
        _next_floor(0),
        _next_floor_pos(0,0)
    {}
    
    stairs(struct stairs_init_data_t* init_data) :
        stairs()
    {
        init(init_data);
    }

    void init(struct stairs_init_data_t* init_data);
    int get_next_floor() { return _next_floor; }
    bn::fixed_point get_next_floor_pos() { return _next_floor_pos; }

private:
    int _next_floor;
    bn::fixed_point _next_floor_pos;
};

}
#endif
