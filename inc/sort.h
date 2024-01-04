#ifndef T
#error Template parameter T was not defined.
#endif

#include "template.h"

// Useful swap macro
#define SWAP(a, b, T) \
    do                \
    {                 \
        T tmp = a;    \
        a = b;        \
        b = tmp;      \
    } while (0)

// =========================================
//               Bubble sort
// =========================================

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

// =========================================
//              Selection sort
// =========================================

void TEMPLATE(sort_selection, T)(T *array, int count)
{
    for (int current_index = 0; current_index < count; current_index++)
    {
        T min = array[current_index];
        T min_index = current_index;
        for (int min_search_index = current_index + 1; min_search_index < count; min_search_index++)
        {
            if (array[min_search_index] < min)
            {
                min = array[min_search_index];
                min_index = min_search_index;
            }
        }
        SWAP(array[current_index], array[min_index], T);
    }
}

void TEMPLATE(sort_reverse_selection, T)(T *array, int count)
{
    for (int current_index = 0; current_index < count; current_index++)
    {
        T max = array[current_index];
        T max_index = current_index;
        for (int max_search_index = current_index + 1; max_search_index < count; max_search_index++)
        {
            if (array[max_search_index] > max)
            {
                max = array[max_search_index];
                max_index = max_search_index;
            }
        }
        SWAP(array[current_index], array[max_index], T);
    }
}

void TEMPLATE(sort_compare_selection, T)(T *array, int count, int (*compare)(T, T))
{
    for (int current_index = 0; current_index < count; current_index++)
    {
        T min = array[current_index];
        T min_index = current_index;
        for (int min_search_index = current_index + 1; min_search_index < count; min_search_index++)
        {
            if (compare(array[min_search_index], min) < 0)
            {
                min = array[min_search_index];
                min_index = min_search_index;
            }
        }
        SWAP(array[current_index], array[min_index], T);
    }
}

#undef SWAP
#undef T
