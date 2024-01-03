#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include "../template.h"

#undef T
#define T int32_t
#include "sort.template.h"

#undef T
#define T float
#include "sort.template.h"

#undef T
#define T double
#include "sort.template.h"

#define sort_bubble(array, count) _Generic((array), \
    int32_t *: TEMPLATE(sort_bubble, int32_t),      \
    float *: TEMPLATE(sort_bubble, float),          \
    double *: TEMPLATE(sort_bubble, double))(array, count)

#endif