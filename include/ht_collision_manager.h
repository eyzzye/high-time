#ifndef HT_COLLISION_MANAGER_H
#define HT_COLLISION_MANAGER_H

#define HT_COLLISION_MANAGER_DEBUG_LOG false

#include "bn_assert.h"
#include "bn_fixed.h"
#include "bn_fixed_rect.h"
#include "bn_vector.h"
#include "bn_list.h"
#include "bn_math.h"
#include "bn_log.h"

#include "ht_common.h"

namespace ht::collision_manager {

enum class body_type {
    STATIC,
    DYNAMIC
};

enum class body_stat {
    INACTIVE,
    ACTIVE
};

class rect_body;
typedef void (*collision_handler)(rect_body* body_a, rect_body* body_b);

struct callback_data_t {
    collision_handler callback;
    rect_body* body_a;
    rect_body* body_b;
};

class velocity {
public:
    velocity(const bn::fixed& vx, const bn::fixed& vy):
        _vx(vx),
        _vy(vy)
    {}

    const bn::fixed& vx() const { return _vx; }
    const bn::fixed& vy() const { return _vy; }
    void set_vx(const bn::fixed& vx) { _vx = vx; }
    void set_vy(const bn::fixed& vy) { _vy = vy; }
    bn::fixed length() { return bn::sqrt((_vx * _vx) + (_vy * _vy)); }

private:
    bn::fixed _vx;
    bn::fixed _vy;
};

// rect = (center_x, center_y, width, height)
class rect_body {
public:
    rect_body(ht::collision_manager::body_type type, const bn::fixed_rect& rect):
        _body_type(type),
        _body_stat(body_stat::ACTIVE),
        _rect(rect),
        _velocity(0,0),
        _collision_callback(NULL),
        _user_data(NULL)
    {}

    rect_body(const bn::fixed_rect& rect):
        rect_body(body_type::STATIC, rect)
    {}

    const ht::collision_manager::body_type& type() const { return _body_type; }
    const ht::collision_manager::body_stat& stat() const { return _body_stat; }
    const bn::fixed_rect& rect() const { return _rect; }
    const ht::collision_manager::velocity& velocity() const { return _velocity; }
    collision_handler collision_callback() const { return _collision_callback; }
    void* user_data() { return _user_data; }

    void set_stat(const ht::collision_manager::body_stat& stat_val) { _body_stat = stat_val; }
    void set_position(const bn::fixed_point& pos) { _rect.set_x(pos.x()); _rect.set_y(pos.y()); }
    void set_velocity(const ht::collision_manager::velocity& vel);
    void set_collision_callback(collision_handler func) { _collision_callback = func; };
    void set_user_data(void* user_data) { _user_data = user_data; };

private:
    ht::collision_manager::body_type _body_type;
    ht::collision_manager::body_stat _body_stat;
    bn::fixed_rect _rect;
    ht::collision_manager::velocity _velocity;

    collision_handler _collision_callback;
    void* _user_data;
};

// world step => v [pixel/sec]
// timestep   => t [sec]
class world {
public:
    world():
        _timestep(1.0f),
        _current_time(0.0f)
    {}

    void init(bn::fixed& timestep);
    void step();

    rect_body& create_rect_body(ht::collision_manager::body_type body_type_val, const bn::fixed_rect& rect_ref);

private:
    bn::fixed _timestep;
    bn::fixed _current_time;
    bn::vector<ht::collision_manager::rect_body, 64> _body_list;

    // cache data
    bn::list<ht::collision_manager::rect_body*, 32> _cache_static_list;
    bn::list<ht::collision_manager::rect_body*, 32> _cache_dynamic_list;

    void _solve_collision_to_static(ht::collision_manager::rect_body& body_ref);
    void _solve_collision_to_dynamic(ht::collision_manager::rect_body& body_ref);

#if HT_COLLISION_MANAGER_DEBUG_LOG 
    bn::fixed _debug_time;
#endif
};

// extern functions
void init(bn::fixed& timestep);
void update();
rect_body& create_rect_body(ht::collision_manager::body_type body_type_val, const bn::fixed_rect& rect_ref);

}
#endif
