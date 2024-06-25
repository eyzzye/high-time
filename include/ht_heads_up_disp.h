#ifndef HT_HEADS_UP_DISP_H
#define HT_HEADS_UP_DISP_H

#include "bn_vector.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_text_generator.h"

#include "bn_sprite_items_digit_numbers_8x16.h"
#include "bn_sprite_items_digit_numbers.h"
#include "bn_sprite_items_digit_numbers_red.h"
#include "bn_sprite_items_item_key.h"

#include "ht_common.h"

namespace ht {

class hud {
public:
    hud();
    void update();

    void set_enable(bool on);
    void set_time(int sec_time);
    void set_palette_red(bool on);

private:
    bool _enable;

    // dirt flag
    bool _dirt_time;

    // time
    int _time;
    static const int _time_sprite_size = 5;
    bn::vector<bn::sprite_ptr, _time_sprite_size> _time_sprite;

    // hero stat -> item_key
    int _item_key_count;
    static const int _item_key_sprite_size = 4;
    bn::vector<bn::sprite_ptr, _item_key_sprite_size> _item_key_sprite;
};

}

#endif
