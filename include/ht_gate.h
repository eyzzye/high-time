#ifndef HT_GATE_H
#define HT_GATE_H

#include "ht_common.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

enum class gate_actions {
    NONE=0,
    OPEN=1,
    CLOSE=2,
};

struct gate_init_data_t {
    bn::fixed_rect rect;
    ht::directions direction;
};

class gate : public object {
public:
    gate():
        object(ht::object::type::EVENT, (int)ht::object::event_id::GATE),
        _body(NULL),
        _direction(ht::directions::DOWN)
    {}

    gate(struct gate_init_data_t* init_data, int list_index):
        gate()
    {
        init(init_data, list_index);
    }

    void init(struct gate_init_data_t* init_data, int list_index);
    void open();
    void close();
    int get_list_index() { return _list_index; }
    ht::directions get_direction() { return _direction; }
    bn::fixed_point* get_bg_map_pos() { return _bg_map_pos; }
    bool on_gate(bn::fixed_point& pos);
    bool is_closed() { return (_body->stat() == ht::collision_manager::body_stat::ACTIVE); }

private:
    int _list_index;
    ht::collision_manager::rect_body* _body;
    ht::directions _direction;
    bn::fixed_point _bg_map_pos[8];
};

}
#endif
