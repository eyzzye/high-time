#include "ht_trace_manager.h"
#include "ht_scene_game.h"

#include "bn_vector.h"
#include "bn_memory.h"
#include "bn_assert.h"
#include "bn_log.h"

extern ht::game* g_game_ptr;

namespace ht::trace_manager {

class static_data {
public:
    bn::vector<struct area_t, 32> area_list;
    bn::vector<struct connection_t, 64> connection_list;

    static const int trace_data_max = 8;
    trace_list_t trace_data[trace_data_max];
    int trace_data_count = 0;

    bn::fixed_point target_pos;
    int target_area_index;
};

BN_DATA_EWRAM static_data data;

void init() {
    if (data.area_list.size() > 0) data.area_list.clear();
    if (data.connection_list.size() > 0) data.connection_list.clear();

    for (int i = 0; i < data.trace_data_count; i++) {
        data.trace_data[i].clear();
    }
    data.trace_data_count = 0;
    data.target_pos.set_x(0);
    data.target_pos.set_y(0);
    data.target_area_index = 0;
}

void init_area(struct array_t<struct area_init_data_t>* list) {
    for (int i = 0; i < (int)list->size; i++) {
        data.area_list.emplace_back();
        auto new_area = data.area_list.end() - 1;
        new_area->rect = list->data[i].rect;
        new_area->next.clear();
    }
}

void init_connections(struct array_t<struct connection_init_data_t>* list) {
    for (int i = 0; i < (int)list->size; i++) {
        data.connection_list.emplace_back();
        auto new_cnn = data.connection_list.end() - 1;
        new_cnn->area_a = &data.area_list[list->data[i].area_index_a];
        new_cnn->area_b = &data.area_list[list->data[i].area_index_b];
        new_cnn->connection_a = list->data[i].connection_a;
        new_cnn->connection_b = list->data[i].connection_b;

#ifdef HT_TRACE_MANAGER_DEBUG_ON
        new_cnn->area_a_index = list->data[i].area_index_a;
        new_cnn->area_b_index = list->data[i].area_index_b;
#endif

        new_cnn->area_a->next.emplace_back();
        auto area_a_next = new_cnn->area_a->next.end() - 1;
        *area_a_next = new_cnn;
        new_cnn->area_b->next.emplace_back();
        auto area_b_next = new_cnn->area_b->next.end() - 1;
        *area_b_next = new_cnn;
    }
}

ht::trace_manager::trace_list_t& assigne_trace_data() {
    BN_ASSERT(data.trace_data_count < data.trace_data_max, "assigne_trace_data(): trace_data full.");

    int assigne_index = data.trace_data_count;
    data.trace_data_count += 1;
    return data.trace_data[assigne_index];
}

void update_trace_point(bn::fixed_point& end_pos) {
    data.target_pos = end_pos;
    auto end_x = end_pos.x();
    auto end_y = end_pos.y();

    for (int i = 0; i < data.area_list.size(); i++) {
        bn::fixed_rect* rect_ptr = &data.area_list[i].rect;
        auto x1 = rect_ptr->x() - (rect_ptr->width() / 2);
        auto y1 = rect_ptr->y() - (rect_ptr->height() / 2);
        auto x2 = rect_ptr->x() + (rect_ptr->width() / 2);
        auto y2 = rect_ptr->y() + (rect_ptr->height() /2);

        // AABB box
        if (((x1 <= end_x) && (end_x <= x2)) && ((y1 <= end_y) && (end_y <= y2)))
        {
            data.target_area_index = i;
            break;
        }
    }
}

bool in_target_area(bn::fixed_point& pos) {
    auto x = pos.x();
    auto y = pos.y();

    bn::fixed_rect* rect_ptr = &data.area_list[data.target_area_index].rect;
    auto x1 = rect_ptr->x() - (rect_ptr->width() / 2);
    auto y1 = rect_ptr->y() - (rect_ptr->height() / 2);
    auto x2 = rect_ptr->x() + (rect_ptr->width() / 2);
    auto y2 = rect_ptr->y() + (rect_ptr->height() /2);

    // AABB box
    if (((x1 <= x) && (x <= x2)) && ((y1 <= y) && (y <= y2)))
    {
        return true;
    }

    return false;
}

bool on_closed_gate(bn::fixed_point& pos) {
    return g_game_ptr->on_closed_gate(pos);
}

static bool _trace_next(int& nest_rank_ref,
                        bn::vector<area_t*,64>& footprints_ref,
                        bool& found_target_ref,
                        bn::vector<trace_data_t,64>& result_ref,
                        struct area_t* current_area_ptr,
                        struct area_t* target_area_ptr,
                        bool skip_closed_gate = true)
{
    nest_rank_ref += 1;
    if (nest_rank_ref > 32) {
        nest_rank_ref -= 1;
        return false;
    }

    // set footprints
    footprints_ref.push_back(current_area_ptr);

    if (current_area_ptr->next.size() > 0) {
        for (int cnn_idx = 0; cnn_idx < current_area_ptr->next.size(); cnn_idx++) {
            struct connection_t* cnn_ptr = current_area_ptr->next[cnn_idx];

            // skip footprints
            bool found_footprints = false;
            for (int f_idx = 0; f_idx < footprints_ref.size(); f_idx++) {
                if (cnn_ptr->area_a == current_area_ptr) {
                    if (footprints_ref[f_idx] == cnn_ptr->area_b) {
                        found_footprints = true;
                        break;
                    }
                }
                else if (cnn_ptr->area_b == current_area_ptr) {
                    if (footprints_ref[f_idx] == cnn_ptr->area_a) {
                        found_footprints = true;
                        break;
                    }
                }
            }
            if (found_footprints) continue;

            // search next
            if (cnn_ptr->area_a == current_area_ptr) {
                // skip closed gate
                if (skip_closed_gate && on_closed_gate(cnn_ptr->connection_b)) {
                    continue;
                }

                // search connection_b
                if (target_area_ptr == cnn_ptr->area_b) {
                    // reach end
#ifdef HT_TRACE_MANAGER_DEBUG_ON
                    struct trace_data_t new_track1 = { cnn_ptr->connection_b, cnn_ptr->area_b_index };
                    struct trace_data_t new_track2 = { cnn_ptr->connection_a, cnn_ptr->area_a_index };
#else
                    struct trace_data_t new_track1 = { cnn_ptr->connection_b };
                    struct trace_data_t new_track2 = { cnn_ptr->connection_a };
#endif

                    result_ref.push_back(new_track1);
                    result_ref.push_back(new_track2);

                    found_target_ref = true;
                    footprints_ref.pop_back();
                    nest_rank_ref -= 1;
                    return true;
                }
                else {
                    // search nest
                    if(_trace_next(nest_rank_ref, footprints_ref, found_target_ref, result_ref,
                                   cnn_ptr->area_b, target_area_ptr, skip_closed_gate))
                    {
#ifdef HT_TRACE_MANAGER_DEBUG_ON
                        struct trace_data_t new_track1 = { cnn_ptr->connection_b, cnn_ptr->area_b_index };
                        struct trace_data_t new_track2 = { cnn_ptr->connection_a, cnn_ptr->area_a_index };
#else
                        struct trace_data_t new_track1 = { cnn_ptr->connection_b };
                        struct trace_data_t new_track2 = { cnn_ptr->connection_a };
#endif
                        result_ref.push_back(new_track1);
                        result_ref.push_back(new_track2);

                        footprints_ref.pop_back();
                        nest_rank_ref -= 1;
                        return true;
                    }
                }
            }
            else if (cnn_ptr->area_b == current_area_ptr) {
                // skip closed gate
                if (skip_closed_gate && on_closed_gate(cnn_ptr->connection_a)) {
                    continue;
                }

                // search connection_a
                if (target_area_ptr == cnn_ptr->area_a) {
                    // reach end
#ifdef HT_TRACE_MANAGER_DEBUG_ON
                    struct trace_data_t new_track1 = { cnn_ptr->connection_a, cnn_ptr->area_a_index };
                    struct trace_data_t new_track2 = { cnn_ptr->connection_b, cnn_ptr->area_b_index };
#else
                    struct trace_data_t new_track1 = { cnn_ptr->connection_a };
                    struct trace_data_t new_track2 = { cnn_ptr->connection_b };
#endif
                    result_ref.push_back(new_track1);
                    result_ref.push_back(new_track2);

                    found_target_ref = true;
                    footprints_ref.pop_back();
                    nest_rank_ref -= 1;
                    return true;
                }
                else {
                    // search nest
                    if(_trace_next(nest_rank_ref, footprints_ref, found_target_ref, result_ref,
                                   cnn_ptr->area_a, target_area_ptr, skip_closed_gate))
                    {
#ifdef HT_TRACE_MANAGER_DEBUG_ON
                        struct trace_data_t new_track1 = { cnn_ptr->connection_a, cnn_ptr->area_a_index };
                        struct trace_data_t new_track2 = { cnn_ptr->connection_b, cnn_ptr->area_b_index };
#else
                        struct trace_data_t new_track1 = { cnn_ptr->connection_a };
                        struct trace_data_t new_track2 = { cnn_ptr->connection_b };
#endif
                        result_ref.push_back(new_track1);
                        result_ref.push_back(new_track2);

                        footprints_ref.pop_back();
                        nest_rank_ref -= 1;
                        return true;
                    }
                }
            }
            else {
                BN_ERROR("get_trace_route(): invalid connection.");
            }
        }
    }

    footprints_ref.pop_back();
    nest_rank_ref -= 1;
    return false;
}

void get_trace_route(trace_list_t& trace_list, bn::fixed_point start_pos) {
    int start_area_index = HT_UNINITIALIZED;

    // get start_area
    auto start_x = start_pos.x();
    auto start_y = start_pos.y();

    for (int i = 0; i < data.area_list.size(); i++) {
        bn::fixed_rect* rect_ptr = &data.area_list[i].rect;
        auto x1 = rect_ptr->x() - (rect_ptr->width() / 2);
        auto y1 = rect_ptr->y() - (rect_ptr->height() / 2);
        auto x2 = rect_ptr->x() + (rect_ptr->width() / 2);
        auto y2 = rect_ptr->y() + (rect_ptr->height() /2);

        // AABB box
        if (((x1 <= start_x) && (start_x <= x2)) && ((y1 <= start_y) && (start_y <= y2)))
        {
            start_area_index = i;
            break;
        }
    }

    // clear old list
    if (trace_list.size() > 0) {
        trace_list.clear();
    }

    if (start_area_index == HT_UNINITIALIZED) {
        // not found. return empty.
        return;
    }

    if (start_area_index == data.target_area_index) {
        trace_list.emplace_back();
        auto new_list = trace_list.end() - 1;
        new_list->pos.set_x(data.area_list[start_area_index].rect.x());
        new_list->pos.set_y(data.area_list[start_area_index].rect.y());
        return;
    }

    // reach target_area
    bn::vector<area_t*,64> footprints;
    int current_area_index = start_area_index;
    struct area_t* current_area_ptr = &data.area_list[current_area_index];
    struct area_t* target_area_ptr = &data.area_list[data.target_area_index];

    bn::vector<trace_data_t,64> result;
    bool found_target = false;
    int nest_rank = 0;
    if(_trace_next(nest_rank, footprints, found_target, result,
                   current_area_ptr, target_area_ptr) == true)
    {
        int new_idx = 0;
        for(int res_idx = result.size() - 1; res_idx >= 0; res_idx--) {
            trace_list.emplace_back();
            auto new_list = trace_list.end() - 1;
            new_list->pos = result[res_idx].pos;

#ifdef HT_TRACE_MANAGER_DEBUG_ON
            int pos_x = result[res_idx].pos.x().right_shift_integer();
            int pos_y = result[res_idx].pos.y().right_shift_integer();
            BN_LOG("area=", result[res_idx].area_index, ", x=", pos_x, ", y=", pos_y);
#endif

            new_idx++;
        }
        return;
    }
    else {
        footprints.clear();
        result.clear();
        nest_rank = 0;
        if(_trace_next(nest_rank, footprints, found_target, result,
                       current_area_ptr, target_area_ptr, false) == true)
        {
            int new_idx = 0;
            for(int res_idx = result.size() - 1; res_idx >= 0; res_idx--) {
                trace_list.emplace_back();
                auto new_list = trace_list.end() - 1;
                new_list->pos = result[res_idx].pos;

#ifdef HT_TRACE_MANAGER_DEBUG_ON
                int pos_x = result[res_idx].pos.x().right_shift_integer();
                int pos_y = result[res_idx].pos.y().right_shift_integer();
                BN_LOG("area=", result[res_idx].area_index, ", x=", pos_x, ", y=", pos_y);
#endif

                new_idx++;
            }
            return;
        }

        // not found. return empty.
        return;
    }
}

struct area_t* get_area(bn::fixed_point& pos) {
    auto pos_x = pos.x();
    auto pos_y = pos.y();

    for (int i = 0; i < data.area_list.size(); i++) {
        bn::fixed_rect* rect_ptr = &data.area_list[i].rect;
        auto x1 = rect_ptr->x() - (rect_ptr->width() / 2);
        auto y1 = rect_ptr->y() - (rect_ptr->height() / 2);
        auto x2 = rect_ptr->x() + (rect_ptr->width() / 2);
        auto y2 = rect_ptr->y() + (rect_ptr->height() /2);

        // AABB box
        if (((x1 <= pos_x) && (pos_x <= x2)) && ((y1 <= pos_y) && (pos_y <= y2)))
        {
            return &data.area_list[i];
        }
    }
    return NULL;
}

}

