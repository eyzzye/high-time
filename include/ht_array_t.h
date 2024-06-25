#ifndef HT_ARRAY_T_H
#define HT_ARRAY_T_H

namespace ht
{

template <typename T> 
struct array_t {
    size_t size;
    T *data;
};

}
#endif

