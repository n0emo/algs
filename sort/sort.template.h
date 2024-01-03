#ifdef T
#include "../template.h"

void TEMPLATE(sort_bubble, T)(T *array, int count);
void TEMPLATE(sort_reverse_bubble, T)(T *array, int count);
void TEMPLATE(sort_compare_bubble, T)(T *array, int count, int (*compare)(T, T));

#endif