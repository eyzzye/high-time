#ifndef HT_TERRAIN_H
#define HT_TERRAIN_H

#include "bn_vector.h"
#include "bn_regular_bg_ptr.h"

#include "ht_common.h"
#include "ht_array_t.h"
#include "ht_object.h"
#include "ht_collision_manager.h"

namespace ht {

struct terrain_init_data_t {
    bn::fixed_rect collision_rect_list;
};

class terrain : public object {
public:
    terrain():
        object(ht::object::type::TERRAIN)
    {}

    void init(struct array_t<ht::terrain_init_data_t>* init_list);

private:
    bn::vector<ht::collision_manager::rect_body*, 32> _rect_ptr_list;
};

}
#endif
