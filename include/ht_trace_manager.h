#ifndef HT_TRACE_MANAGER_H
#define HT_TRACE_MANAGER_H

#include "bn_fixed.h"
#include "bn_fixed_point.h"
#include "bn_fixed_rect.h"
#include "bn_vector.h"

#include "ht_common.h"
#include "ht_array_t.h"

//#define HT_TRACE_MANAGER_DEBUG_ON true

namespace ht::trace_manager {

struct connection_t;
struct trace_data_t;
using trace_list_t = bn::vector<ht::trace_manager::trace_data_t,64>;

//
// internal trace infomation
//
struct area_t {
    bn::fixed_rect rect;
    bn::vector<struct connection_t*, 8> next;
};

struct connection_t {
    struct area_t* area_a;
    struct area_t* area_b;
    bn::fixed_point connection_a;
    bn::fixed_point connection_b;

#ifdef HT_TRACE_MANAGER_DEBUG_ON
    int area_a_index;
    int area_b_index;
#endif
};

//
// initialize infomation
//
struct area_init_data_t {
    bn::fixed_rect rect;
};

struct connection_init_data_t {
    int area_index_a;
    int area_index_b;
    bn::fixed_point connection_a;
    bn::fixed_point connection_b;
};

//
// trace route infomation
//
struct trace_data_t {
    bn::fixed_point pos;

#ifdef HT_TRACE_MANAGER_DEBUG_ON
    int area_index;
#endif
};


// extern functions
void init();
void init_area(struct array_t<struct area_init_data_t>* list);
void init_connections(struct array_t<struct connection_init_data_t>* list);
ht::trace_manager::trace_list_t& assigne_trace_data();
void update_trace_point(bn::fixed_point& end_pos);
bool in_target_area(bn::fixed_point& pos);
bool on_closed_gate(bn::fixed_point& pos);
void get_trace_route(trace_list_t& trace_list, bn::fixed_point start_pos);
struct area_t* get_area(bn::fixed_point& pos);

}

#endif
