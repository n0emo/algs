#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include "../template.h"

typedef void* void_ptr;

#undef T
#define T int32_t
#include "sort.template.h"

#undef T
#define T float
#include "sort.template.h"

#undef T
#define T double
#include "sort.template.h"

#undef T
#define T void_ptr
#include "sort.template.h"

#define sort_bubble(array, count) _Generic((array), \
    int32_t *: TEMPLATE(sort_bubble, int32_t),      \
    float *: TEMPLATE(sort_bubble, float),          \
    double *: TEMPLATE(sort_bubble, double), \
    default: TEMPLATE(sort_bubble, void_ptr))(array, count)

#define sort_reverse_bubble(array, count) _Generic((array), \
    int32_t *: TEMPLATE(sort_reverse_bubble, int32_t),      \
    float *: TEMPLATE(sort_reverse_bubble, float),          \
    double *: TEMPLATE(sort_reverse_bubble, double), \
    default: TEMPLATE(sort_reverse_bubble, void_ptr))(array, count)

#define sort_compare_bubble(array, count, compare) _Generic((array), \
    int32_t *: TEMPLATE(sort_compare_bubble, int32_t),      \
    float *: TEMPLATE(sort_compare_bubble, float),          \
    double *: TEMPLATE(sort_compare_bubble, double), \
    default: TEMPLATE(sort_compare_bubble, void_ptr))(array, count, compare)

#endif