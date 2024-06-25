#include "ht_collision_manager.h"

namespace ht::collision_manager
{

class static_data {
public:
    world world_data;
};

BN_DATA_EWRAM static_data data;

void world::init(bn::fixed& timestep) {
    _timestep = timestep;
    _current_time = 0.0f;
    _body_list.clear();

    _cache_static_list.clear();
    _cache_dynamic_list.clear();

#if HT_COLLISION_MANAGER_DEBUG_LOG
    _debug_time = 0.0f;
#endif
}

void rect_body::set_velocity(const ht::collision_manager::velocity& vel) {
    BN_ASSERT(_body_type == body_type::DYNAMIC, "rect_body::set_velocity() called by STATIC body");

    if (_body_stat != body_stat::ACTIVE) {
        _body_stat = body_stat::ACTIVE;
    }

    _velocity.set_vx(vel.vx());
    _velocity.set_vy(vel.vy());
}

void world::step() {
    _current_time += _timestep;

#if HT_COLLISION_MANAGER_DEBUG_LOG 
    if ((_current_time - _debug_time).integer() > 0) {
        BN_LOG("current time[sec]: ", _current_time.integer());
        _debug_time = _current_time;
    }
#endif

    // update all bodies
    for(ht::collision_manager::rect_body* current_body : _cache_dynamic_list) {
        _solve_collision_to_static(*current_body);
        _solve_collision_to_dynamic(*current_body);
    }
}

rect_body& world::create_rect_body(ht::collision_manager::body_type body_type_val, const bn::fixed_rect& rect_ref) {
    _body_list.push_back(rect_body(body_type_val, rect_ref));

    rect_body* tmp_body = &_body_list[(_body_list.size() - 1)];
    switch (tmp_body->type()) {
    case body_type::STATIC:
        _cache_static_list.push_back(tmp_body);
        break;
    case body_type::DYNAMIC:
        _cache_dynamic_list.push_back(tmp_body);
        break;
    default:
        BN_ERROR("Invalid body_type: ", (int)tmp_body->type());
        break;
    }

    return _body_list[(_body_list.size() - 1)];
}

void init(bn::fixed& timestep) {
    data.world_data.init(timestep);
}

void update() {
    data.world_data.step();
}

rect_body& create_rect_body(ht::collision_manager::body_type body_type_val, const bn::fixed_rect& rect_ref) {
    return data.world_data.create_rect_body(body_type_val, rect_ref);
}

void world::_solve_collision_to_static(ht::collision_manager::rect_body& body_ref) {
    bn::vector<struct ht::collision_manager::callback_data_t, 32> callback_list;

    bn::fixed_point current_pos(body_ref.rect().x(), body_ref.rect().y());
    bn::fixed current_width = body_ref.rect().width();
    bn::fixed current_height = body_ref.rect().height();
    bn::fixed_point new_pos = current_pos;

    ht::collision_manager::velocity vel = body_ref.velocity();
    if (vel.vx() != 0) { new_pos.set_x(current_pos.x() + (vel.vx() * _timestep)); }
    if (vel.vy() != 0) { new_pos.set_y(current_pos.y() + (vel.vy() * _timestep)); }

    for (auto b_ref: _cache_static_list ) {
        // skip myself
        if (b_ref == (&body_ref)) { continue; }
        if (b_ref->stat() == ht::collision_manager::body_stat::INACTIVE) { continue; }

        const bn::fixed_rect& b_rect = b_ref->rect();
        bool x_overlap_flg = false;
        bool y_overlap_flg = false;
        bool new_x_shorter;
        bool new_y_shorter;
        bool rect_overlap_flg[4] = {false, false, false, false}; // DOWN, UP, RIGHT, LEFT

        bn::fixed overlap_x = 0;
        bn::fixed overlap_y = 0;
        bn::fixed overlap_width = 0;
        bn::fixed overlap_height = 0;

        // new_x1      new_x2
        // |           |
        // +-----------+
        //        +-------------------+
        //        |                   |
        //        b_x1                b_x2
        bn::fixed new_x1 = new_pos.x() - current_width/2;
        bn::fixed new_x2 = new_pos.x() + current_width/2;
        bn::fixed b_x1 = b_rect.x() - b_rect.width()/2;
        bn::fixed b_x2 = b_rect.x() + b_rect.width()/2;

        if (b_rect.width() >= current_width) {
            new_x_shorter = true;
            if ((b_x1 <= new_x1) && (b_x2 >= new_x1)) {
                x_overlap_flg = true;
                rect_overlap_flg[(int)ht::directions::LEFT] = true;
            }
            if ((b_x1 <= new_x2) && (b_x2 >= new_x2)) {
                x_overlap_flg = true;
                rect_overlap_flg[(int)ht::directions::RIGHT] = true;
            }
        }
        else {
            new_x_shorter = false;
            if ((new_x1 <= b_x1) && (new_x2 >= b_x1)) {
                x_overlap_flg = true;
                rect_overlap_flg[(int)ht::directions::LEFT] = true;
            }
            if ((new_x1 <= b_x2) && (new_x2 >= b_x2)) {
                x_overlap_flg = true;
                rect_overlap_flg[(int)ht::directions::RIGHT] = true;
            }
        }

        // new_y1  --+
        //           | +-- b_y1
        //           | |
        // new_y2  --+ |
        //             |
        //             +-- b_y2
        bn::fixed new_y1 = new_pos.y() - current_height/2;
        bn::fixed new_y2 = new_pos.y() + current_height/2;
        bn::fixed b_y1 = b_rect.y() - b_rect.height()/2;
        bn::fixed b_y2 = b_rect.y() + b_rect.height()/2;

        if (b_rect.height() >= current_height) {
            new_y_shorter = true;
            if ((b_y1 <= new_y1) && (b_y2 >= new_y1)) {
                y_overlap_flg = true;
                rect_overlap_flg[(int)ht::directions::UP] = true;
            }
            if ((b_y1 <= new_y2) && (b_y2 >= new_y2)) {
                y_overlap_flg = true;
                rect_overlap_flg[(int)ht::directions::DOWN] = true;
            }
        }
        else {
            new_y_shorter = false;
            if ((new_y1 <= b_y1) && (new_y2 >= b_y1)) {
                rect_overlap_flg[(int)ht::directions::UP] = true;
                y_overlap_flg = true;
            }
            if ((new_y1 <= b_y2) && (new_y2 >= b_y2)) {
                rect_overlap_flg[(int)ht::directions::DOWN] = true;
                y_overlap_flg = true;
            }
        }

        if (x_overlap_flg && y_overlap_flg) {
            collision_handler callback_func = body_ref.collision_callback();
            if (callback_func != NULL) {
                struct callback_data_t cd = { callback_func, &body_ref, b_ref };
                callback_list.push_back(cd);
            }
        }

        // reaction
        if (x_overlap_flg && y_overlap_flg) {
            // x-overlap
            if (rect_overlap_flg[(int)ht::directions::LEFT] &&
                rect_overlap_flg[(int)ht::directions::RIGHT]) {
                overlap_x = new_x_shorter ? new_x1 : b_x1;
                overlap_width = new_x_shorter ? current_width : b_rect.width();
            }
            else if (rect_overlap_flg[(int)ht::directions::LEFT]) {
                overlap_x = new_x_shorter ? new_x1 : b_x1;
                overlap_width = new_x_shorter ? bn::abs(b_x2 - new_x1) : bn::abs(new_x2 - b_x1);
            }
            else if (rect_overlap_flg[(int)ht::directions::RIGHT]) {
                overlap_x = new_x_shorter ? b_x1 : new_x1;
                overlap_width = new_x_shorter ? bn::abs(new_x2 - b_x1) : bn::abs(b_x2 - new_x1);
            }

            // y-overlap
            if (rect_overlap_flg[(int)ht::directions::UP] &&
                rect_overlap_flg[(int)ht::directions::DOWN]) {
                overlap_y = new_y_shorter ? new_y1 : b_y1;
                overlap_height = new_y_shorter ? current_height : b_rect.height();
            }
            else if (rect_overlap_flg[(int)ht::directions::UP]) {
                overlap_y = new_y_shorter ? new_y1 : b_y1;
                overlap_height = new_y_shorter ? bn::abs(b_y2 - new_y1) : bn::abs(new_y2 - b_y1);
            }
            else if (rect_overlap_flg[(int)ht::directions::DOWN]) {
                overlap_y = new_y_shorter ? b_y1 : new_y1;
                overlap_height = new_y_shorter ? bn::abs(new_y2 - b_y1) : bn::abs(b_y2 - new_y1);
            }

            // resolve
            bool push_direction_flg[4] = {false, false, false, false};
            if (rect_overlap_flg[(int)ht::directions::LEFT] &&
                rect_overlap_flg[(int)ht::directions::RIGHT] &&
                rect_overlap_flg[(int)ht::directions::UP] &&
                rect_overlap_flg[(int)ht::directions::DOWN]) {
                // include all -> return to current side
                if (bn::abs(vel.vx()) > bn::abs(vel.vy())) {
                    if (vel.vx() >= 0) {
                        push_direction_flg[(int)ht::directions::LEFT] = true;
                    }
                    else if (vel.vx() < 0) {
                        push_direction_flg[(int)ht::directions::RIGHT] = true;
                    }
                }
                else {
                    if (vel.vy() >= 0) {
                        push_direction_flg[(int)ht::directions::UP] = true;
                    }
                    else if (vel.vy() < 0) {
                        push_direction_flg[(int)ht::directions::DOWN] = true;
                    }
                }
            }
            else if (overlap_width <= overlap_height) {
                if (rect_overlap_flg[(int)ht::directions::LEFT] &&
                    rect_overlap_flg[(int)ht::directions::RIGHT]) {
                    if (vel.vx() >= 0) {
                        push_direction_flg[(int)ht::directions::LEFT] = true;
                    }
                    else if (vel.vx() < 0) {
                        push_direction_flg[(int)ht::directions::RIGHT] = true;
                    }
                }
                else if (rect_overlap_flg[(int)ht::directions::LEFT]) {
                    if (new_x_shorter) {
                        push_direction_flg[(int)ht::directions::RIGHT] = true;
                    }
                    else {
                        push_direction_flg[(int)ht::directions::LEFT] = true;
                    }
                }
                else if (rect_overlap_flg[(int)ht::directions::RIGHT]) {
                    if (new_x_shorter) {
                        push_direction_flg[(int)ht::directions::LEFT] = true;
                    }
                    else {
                        push_direction_flg[(int)ht::directions::RIGHT] = true;
                    }
                }
            }
            else {
                if (rect_overlap_flg[(int)ht::directions::UP] &&
                    rect_overlap_flg[(int)ht::directions::DOWN]) {
                    if (vel.vy() >= 0) {
                        push_direction_flg[(int)ht::directions::UP] = true;
                    }
                    else if (vel.vy() < 0) {
                        push_direction_flg[(int)ht::directions::DOWN] = true;
                    }
                }
                else if (rect_overlap_flg[(int)ht::directions::UP]) {
                    if (new_y_shorter) {
                        push_direction_flg[(int)ht::directions::DOWN] = true;
                    }
                    else {
                        push_direction_flg[(int)ht::directions::UP] = true;
                    }
                }
                else if (rect_overlap_flg[(int)ht::directions::DOWN]) {
                    if (new_y_shorter) {
                        push_direction_flg[(int)ht::directions::UP] = true;
                    }
                    else {
                        push_direction_flg[(int)ht::directions::DOWN] = true;
                    }
                }
            }

            // set new_pos
            if (push_direction_flg[(int)ht::directions::LEFT]) {
                new_pos.set_x(new_pos.x() - bn::abs(new_x2 - b_x1));
            }
            if (push_direction_flg[(int)ht::directions::RIGHT]) {
                new_pos.set_x(new_pos.x() + bn::abs(b_x2 - new_x1));
            }
            if (push_direction_flg[(int)ht::directions::UP]) {
                new_pos.set_y(new_pos.y() - bn::abs(new_y2 - b_y1));
            }
            if (push_direction_flg[(int)ht::directions::DOWN]) {
                new_pos.set_y(new_pos.y() + bn::abs(b_y2 - new_y1));
            }
        }

        body_ref.set_position(new_pos);
    }

    // callback collision_handler
    for (auto cd_ref : callback_list) {
        (*cd_ref.callback)(cd_ref.body_a, cd_ref.body_b);
    }
}

void world::_solve_collision_to_dynamic(ht::collision_manager::rect_body& body_ref) {
    bn::vector<struct ht::collision_manager::callback_data_t, 32> callback_list;

    bn::fixed_point current_pos(body_ref.rect().x(), body_ref.rect().y());
    bn::fixed current_width = body_ref.rect().width();
    bn::fixed current_height = body_ref.rect().height();

    for (auto b_ref: _cache_dynamic_list ) {
        // skip myself
        if (b_ref == (&body_ref)) { continue; }
        if (b_ref->stat() == ht::collision_manager::body_stat::INACTIVE) { continue; }

        const bn::fixed_rect& b_rect = b_ref->rect();
        bool x_overlap_flg = false;
        bool y_overlap_flg = false;

        if (b_rect.width() >= current_width) {
            if (((b_rect.x() - b_rect.width()/2) <= (current_pos.x() - current_width/2) &&
                 (b_rect.x() + b_rect.width()/2) >= (current_pos.x() - current_width/2)) ||
                ((b_rect.x() - b_rect.width()/2) <= (current_pos.x() + current_width/2) &&
                 (b_rect.x() + b_rect.width()/2) >= (current_pos.x() + current_width/2)))
            {
                x_overlap_flg = true;
            }
        }
        else {
            if (((current_pos.x() - current_width/2) <= (b_rect.x() - b_rect.width()/2) &&
                 (current_pos.x() + current_width/2) >= (b_rect.x() - b_rect.width()/2)) ||
                ((current_pos.x() - current_width/2) <= (b_rect.x() + b_rect.width()/2) &&
                 (current_pos.x() + current_width/2) >= (b_rect.x() + b_rect.width()/2)))
            {
                x_overlap_flg = true;
            }
        }

        if (b_rect.height() >= current_height) {
            if (((b_rect.y() - b_rect.height()/2) <= (current_pos.y() - current_height/2) &&
                 (b_rect.y() + b_rect.height()/2) >= (current_pos.y() - current_height/2)) ||
                ((b_rect.y() - b_rect.height()/2) <= (current_pos.y() + current_height/2) &&
                 (b_rect.y() + b_rect.height()/2) >= (current_pos.y() + current_height/2)))
            {
                y_overlap_flg = true;
            }
        }
        else {
            if (((current_pos.y() - current_height/2) <= (b_rect.y() - b_rect.height()/2) &&
                 (current_pos.y() + current_height/2) >= (b_rect.y() - b_rect.height()/2)) ||
                ((current_pos.y() - current_height/2) <= (b_rect.y() + b_rect.height()/2) &&
                 (current_pos.y() + current_height/2) >= (b_rect.y() + b_rect.height()/2)))
            {
                y_overlap_flg = true;
            }
        }

        if (x_overlap_flg && y_overlap_flg)
        {
            collision_handler callback_func = body_ref.collision_callback();
            if (callback_func != NULL) {
                struct callback_data_t cd = { callback_func, &body_ref, b_ref };
                callback_list.push_back(cd);
            }
        }
    }

    // callback collision_handler
    for (auto cd_ref : callback_list) {
        (*cd_ref.callback)(cd_ref.body_a, cd_ref.body_b);
    }
}

}

