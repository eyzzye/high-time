#ifndef HT_SCORE_H
#define HT_SCORE_H

#include "ht_common.h"

namespace ht {

class score {
public:
    score()
    {
        init();
    }

    void init() {
        for (int i = 0; i < HT_STAGE_MAX; i++) {
            time[i] = 0;
            died[i] = 0;
        }
    }

    int time[HT_STAGE_MAX];
    int died[HT_STAGE_MAX];
};

}

#endif
