#ifndef HT_COMMON_H
#define HT_COMMON_H

#define HT_STAGE_MAX     (4)
#define HT_FLOOR_MAX     (4)
#define HT_STAIRS_MAX    (8)
#define HT_TELEPORT_MAX  (8)
#define HT_GATE_MAX      (8)
#define HT_ITEM_KEY_MAX  (8)

#define HT_Z_ORDER_SPRITE_TOP (-255)
#define HT_UNINITIALIZED (-1)

namespace ht {

enum class directions {
    DOWN=0,
    UP=1,
    RIGHT=2,
    LEFT=3,
};

enum class game_result {
    YET,
    WIN,
    LOSE
};

}

#endif
