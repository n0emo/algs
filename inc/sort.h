#ifndef T
#error Template parameter T was not defined.
#endif

#include "template.h"

#define SWAP(a, b, T) \
    do                \
    {                 \
        T tmp = a;    \
        a = b;        \
        b = tmp;      \
    } while (0)

void TEMPLATE(sort_bubble, T)(T *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (array[i] > array[j])
            {
                SWAP(array[i], array[j], T);
            }
        }
    }
}

void TEMPLATE(sort_reverse_bubble, T)(T *array, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (array[i] < array[j])
            {
                SWAP(array[i], array[j], T);
            }
        }
    }
}

void TEMPLATE(sort_compare_bubble, T)(T *array, int count, int (*compare)(T, T))
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (compare(array[i], array[j]) > 0)
            {
                SWAP(array[i], array[j], T);
            }
        }
    }
}

#undef SWAP
#undef T
