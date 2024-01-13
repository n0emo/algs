#ifdef CLANGD
#include <memory.h>
#include <stdlib.h>
#define SORT_ALLOC malloc
#define SORT_FREE free
#define T int
#endif // CLANGD

#ifndef T
#error Template parameter T was not defined.
#endif // T

#include "template.h"
#include <stdint.h>

// TODO: check if only one of allocs defined

#ifndef SORT_ALLOC
#include <stdlib.h>
#define SORT_ALLOC malloc
#endif // SORT_ALLOC

#ifndef SORT_FREE
#include <stdlib.h>
#define SORT_FREE free
#endif // SORT_FREE

// Useful swap macro
#define SWAP(a, b, T)                                                                                                  \
    do                                                                                                                 \
    {                                                                                                                  \
        T tmp = a;                                                                                                     \
        a = b;                                                                                                         \
        b = tmp;                                                                                                       \
    } while (0)

// =========================================
//               Bubble sort
// =========================================

static inline void TEMPLATE(sort_bubble, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    for (int64_t i = 0; i < count; i++)
    {
        for (int64_t j = i + 1; j < count; j++)
        {
            if (array[i] > array[j])
            {
                SWAP(array[i], array[j], T);
            }
        }
    }
}

static inline void TEMPLATE(sort_reverse_bubble, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    for (int64_t i = 0; i < count; i++)
    {
        for (int64_t j = i + 1; j < count; j++)
        {
            if (array[i] < array[j])
            {
                SWAP(array[i], array[j], T);
            }
        }
    }
}

static inline void TEMPLATE(sort_compare_bubble, T)(T *array, int64_t count, int (*compare)(T, T))
{
    if (count <= 1)
    {
        return;
    }

    for (int64_t i = 0; i < count; i++)
    {
        for (int64_t j = i + 1; j < count; j++)
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

static inline void TEMPLATE(sort_selection, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    for (int64_t current_index = 0; current_index < count; current_index++)
    {
        T min = array[current_index];
        T min_index = current_index;
        for (int64_t min_search_index = current_index + 1; min_search_index < count; min_search_index++)
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

static inline void TEMPLATE(sort_reverse_selection, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    for (int64_t current_index = 0; current_index < count; current_index++)
    {
        T max = array[current_index];
        T max_index = current_index;
        for (int64_t max_search_index = current_index + 1; max_search_index < count; max_search_index++)
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

static inline void TEMPLATE(sort_compare_selection, T)(T *array, int64_t count, int (*compare)(T, T))
{
    if (count <= 1)
    {
        return;
    }

    for (int64_t current_index = 0; current_index < count; current_index++)
    {
        T min = array[current_index];
        T min_index = current_index;
        for (int64_t min_search_index = current_index + 1; min_search_index < count; min_search_index++)
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

// =========================================
//              Inseriton sort
// =========================================

static inline void TEMPLATE(sort_insertion, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    // main loop
    for (int64_t current_index = 1; current_index < count; current_index++)
    {
        T element_to_insert = array[current_index];

        // getting insert index with binary search
        int64_t insert_index = -1;

        int64_t left_index = 0;
        int64_t right_index = current_index - 1;

        while (left_index <= right_index)
        {
            int64_t middle_index = (right_index + left_index) / 2;
            T middle = array[middle_index];
            if (element_to_insert > middle)
            {
                left_index = middle_index + 1;
            }
            else if (element_to_insert < middle)
            {
                right_index = middle_index - 1;
            }
            else
            {
                insert_index = middle_index;
                break;
            }
        }

        if (insert_index == -1)
        {
            insert_index = left_index;
        }

        // inserting element
        for (int swap_index = current_index; swap_index > insert_index; swap_index--)
        {
            SWAP(array[swap_index - 1], array[swap_index], T);
        }
    }
}

static inline void TEMPLATE(sort_reverse_insertion, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    // main loop
    for (int64_t current_index = 1; current_index < count; current_index++)
    {
        T element_to_insert = array[current_index];

        // getting insert index with binary search
        int64_t insert_index = -1;

        int64_t left_index = 0;
        int64_t right_index = current_index - 1;

        while (left_index <= right_index)
        {
            int64_t middle_index = (right_index + left_index) / 2;
            T middle = array[middle_index];
            if (element_to_insert < middle)
            {
                left_index = middle_index + 1;
            }
            else if (element_to_insert > middle)
            {
                right_index = middle_index - 1;
            }
            else
            {
                insert_index = middle_index;
                break;
            }
        }

        if (insert_index == -1)
        {
            insert_index = left_index;
        }

        // inserting element
        for (int swap_index = current_index; swap_index > insert_index; swap_index--)
        {
            SWAP(array[swap_index - 1], array[swap_index], T);
        }
    }
}

static inline void TEMPLATE(sort_compare_insertion, T)(T *array, int64_t count, int (*compare)(T, T))
{
    if (count <= 1)
    {
        return;
    }

    // main loop
    for (int64_t current_index = 1; current_index < count; current_index++)
    {
        T element_to_insert = array[current_index];

        // getting insert index with binary search
        int64_t insert_index = -1;

        int64_t left_index = 0;
        int64_t right_index = current_index - 1;

        while (left_index <= right_index)
        {
            int64_t middle_index = (right_index + left_index) / 2;
            T middle = array[middle_index];
            int compare_result = compare(element_to_insert, middle);
            if (compare_result > 0)
            {
                left_index = middle_index + 1;
            }
            else if (compare_result < 0)
            {
                right_index = middle_index - 1;
            }
            else
            {
                insert_index = middle_index;
                break;
            }
        }

        if (insert_index == -1)
        {
            insert_index = left_index;
        }

        // inserting element
        for (int swap_index = current_index; swap_index > insert_index; swap_index--)
        {
            SWAP(array[swap_index - 1], array[swap_index], T);
        }
    }
}
// =========================================
//              Quick sort
// =========================================

static inline void TEMPLATE(sort_quick, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    // the chosen pivot is middle of an array, but can be changed
    // TODO: better pivot selection
    int64_t pivot_index = count / 2;
    T pivot = array[pivot_index];
    SWAP(array[0], array[pivot_index], T);

    // partitioning array
    int64_t current_index = 1;
    int64_t pivot_position = 0;
    while (current_index < count)
    {
        if (array[current_index] < pivot)
        {
            pivot_position++;
            SWAP(array[current_index], array[pivot_position], T);
        }
        current_index++;
    }
    SWAP(array[0], array[pivot_position], T);

    // sort partitioned subarrays
    TEMPLATE(sort_quick, T)
    (array, pivot_position);
    TEMPLATE(sort_quick, T)
    (array + pivot_position + 1, count - pivot_position - 1);
}

static inline void TEMPLATE(sort_reverse_quick, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    int64_t pivot_index = count / 2;
    T pivot = array[pivot_index];
    SWAP(array[0], array[pivot_index], T);

    int64_t current_index = 1;
    int64_t pivot_position = 0;
    while (current_index < count)
    {
        if (array[current_index] > pivot)
        {
            pivot_position++;
            SWAP(array[current_index], array[pivot_position], T);
        }
        current_index++;
    }
    SWAP(array[0], array[pivot_position], T);

    TEMPLATE(sort_reverse_quick, T)
    (array, pivot_position);
    TEMPLATE(sort_reverse_quick, T)
    (array + pivot_position + 1, count - pivot_position - 1);
}

static inline void TEMPLATE(sort_compare_quick, T)(T *array, int64_t count, int (*compare)(T, T))
{
    if (count <= 1)
    {
        return;
    }

    int64_t pivot_index = count / 2;
    T pivot = array[pivot_index];
    SWAP(array[0], array[pivot_index], T);

    int64_t current_index = 1;
    int64_t pivot_position = 0;
    while (current_index < count)
    {
        if (compare(array[current_index], pivot) < 0)
        {
            pivot_position++;
            SWAP(array[current_index], array[pivot_position], T);
        }
        current_index++;
    }
    SWAP(array[0], array[pivot_position], T);

    TEMPLATE(sort_compare_quick, T)
    (array, pivot_position, compare);
    TEMPLATE(sort_compare_quick, T)
    (array + pivot_position + 1, count - pivot_position - 1, compare);
}

// =========================================
//              Merge sort
// =========================================

static inline void TEMPLATE(sort_merge, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    int64_t middle_index = count / 2;

    // sort left and right
    TEMPLATE(sort_merge, T)
    (array, middle_index);
    TEMPLATE(sort_merge, T)
    (array + middle_index, count - middle_index);

    int64_t left_count = middle_index;
    int64_t right_count = count - middle_index;

    // auxulary arrays
    T *array_left = (T *)SORT_ALLOC(left_count * sizeof(T));
    T *array_right = (T *)SORT_ALLOC(right_count * (sizeof(T)));

    // copy elements to auxulary arrays
    for (int i = 0; i < left_count; i++)
    {
        array_left[i] = array[i];
    }
    for (int i = 0; i < right_count; i++)
    {
        array_right[i] = array[left_count + i];
    }

    // merge elements from auxulary arrays to main array
    int64_t left_current_index = 0;
    int64_t right_current_index = 0;
    int64_t array_current_index = 0;

    while (left_current_index < left_count)
    {
        if (right_current_index < right_count)
        {
            if (array_left[left_current_index] < array_right[right_current_index])
            {
                array[array_current_index] = array_left[left_current_index];
                left_current_index++;
            }
            else
            {
                array[array_current_index] = array_right[right_current_index];
                right_current_index++;
            }
        }
        else
        {
            array[array_current_index] = array_left[left_current_index];
            left_current_index++;
        }
        array_current_index++;
    }

    while (right_current_index < right_count)
    {
        array[array_current_index] = array_right[right_current_index];
        right_current_index++;
        array_current_index++;
    }

    SORT_FREE(array_left);
    SORT_FREE(array_right);
}

static inline void TEMPLATE(sort_reverse_merge, T)(T *array, int64_t count)
{
    if (count <= 1)
    {
        return;
    }

    int64_t middle_index = count / 2;

    // sort left and right
    TEMPLATE(sort_reverse_merge, T)
    (array, middle_index);
    TEMPLATE(sort_reverse_merge, T)
    (array + middle_index, count - middle_index);

    int64_t left_count = middle_index;
    int64_t right_count = count - middle_index;

    // auxulary arrays
    T *array_left = (T *)SORT_ALLOC(left_count * sizeof(T));
    T *array_right = (T *)SORT_ALLOC(right_count * (sizeof(T)));

    // copy elements to auxulary arrays
    for (int i = 0; i < left_count; i++)
    {
        array_left[i] = array[i];
    }
    for (int i = 0; i < right_count; i++)
    {
        array_right[i] = array[left_count + i];
    }

    // merge elements from auxulary arrays to main array
    int64_t left_current_index = 0;
    int64_t right_current_index = 0;
    int64_t array_current_index = 0;

    while (left_current_index < left_count)
    {
        if (right_current_index < right_count)
        {
            if (array_left[left_current_index] > array_right[right_current_index])
            {
                array[array_current_index] = array_left[left_current_index];
                left_current_index++;
            }
            else
            {
                array[array_current_index] = array_right[right_current_index];
                right_current_index++;
            }
        }
        else
        {
            array[array_current_index] = array_left[left_current_index];
            left_current_index++;
        }
        array_current_index++;
    }

    while (right_current_index < right_count)
    {
        array[array_current_index] = array_right[right_current_index];
        right_current_index++;
        array_current_index++;
    }

    SORT_FREE(array_left);
    SORT_FREE(array_right);
}

static inline void TEMPLATE(sort_compare_merge, T)(T *array, int64_t count, int (*compare)(T, T))
{
    if (count <= 1)
    {
        return;
    }

    int64_t middle_index = count / 2;

    // sort left and right
    TEMPLATE(sort_compare_merge, T)
    (array, middle_index, compare);
    TEMPLATE(sort_compare_merge, T)
    (array + middle_index, count - middle_index, compare);

    int64_t left_count = middle_index;
    int64_t right_count = count - middle_index;

    // auxulary arrays
    T *array_left = (T *)SORT_ALLOC(left_count * sizeof(T));
    T *array_right = (T *)SORT_ALLOC(right_count * (sizeof(T)));

    // copy elements to auxulary arrays
    for (int i = 0; i < left_count; i++)
    {
        array_left[i] = array[i];
    }
    for (int i = 0; i < right_count; i++)
    {
        array_right[i] = array[left_count + i];
    }

    // merge elements from auxulary arrays to main array
    int64_t left_current_index = 0;
    int64_t right_current_index = 0;
    int64_t array_current_index = 0;

    while (left_current_index < left_count)
    {
        if (right_current_index < right_count)
        {
            if (compare(array_left[left_current_index], array_right[right_current_index]) < 0)
            {
                array[array_current_index] = array_left[left_current_index];
                left_current_index++;
            }
            else
            {
                array[array_current_index] = array_right[right_current_index];
                right_current_index++;
            }
        }
        else
        {
            array[array_current_index] = array_left[left_current_index];
            left_current_index++;
        }
        array_current_index++;
    }

    while (right_current_index < right_count)
    {
        array[array_current_index] = array_right[right_current_index];
        right_current_index++;
        array_current_index++;
    }

    SORT_FREE(array_left);
    SORT_FREE(array_right);
}

// =========================================
//              Heap sort
// =========================================

static inline void TEMPLATE(downheap, T)(T *array, int64_t count, int64_t root_index)
{
    int64_t largest_index = root_index;
    int64_t left_index = root_index * 2 + 1;
    int64_t right_index = root_index * 2 + 2;

    if (left_index < count && array[left_index] > array[largest_index])
    {
        largest_index = left_index;
    }

    if (right_index < count && array[right_index] > array[largest_index])
    {
        largest_index = right_index;
    }

    if (largest_index != root_index)
    {
        SWAP(array[largest_index], array[root_index], T);
        TEMPLATE(downheap, T)(array, count, largest_index);
    }
}

static inline void TEMPLATE(sort_heap, T)(T *array, int64_t count)
{
    // Building max heap
    for (int64_t root_index = count / 2 - 1; root_index >= 0; root_index--)
    {
        TEMPLATE(downheap, T)(array, count, root_index);
    }

    // Sorting
    for (int64_t current_index = count - 1; current_index >= 0; current_index--)
    {
        SWAP(array[0], array[current_index], T);
        TEMPLATE(downheap, T)(array, current_index, 0);
    }
}

static inline void TEMPLATE(downheap_reverse, T)(T *array, int64_t count, int64_t root_index)
{
    int64_t largest_index = root_index;
    int64_t left_index = root_index * 2 + 1;
    int64_t right_index = root_index * 2 + 2;

    if (left_index < count && array[left_index] < array[largest_index])
    {
        largest_index = left_index;
    }

    if (right_index < count && array[right_index] < array[largest_index])
    {
        largest_index = right_index;
    }

    if (largest_index != root_index)
    {
        SWAP(array[largest_index], array[root_index], T);
        TEMPLATE(downheap_reverse, T)(array, count, largest_index);
    }
}

static inline void TEMPLATE(sort_reverse_heap, T)(T *array, int64_t count)
{
    // Building max heap
    for (int64_t root_index = count / 2 - 1; root_index >= 0; root_index--)
    {
        TEMPLATE(downheap_reverse, T)(array, count, root_index);
    }

    // Sorting
    for (int64_t current_index = count - 1; current_index >= 0; current_index--)
    {
        SWAP(array[0], array[current_index], T);
        TEMPLATE(downheap_reverse, T)(array, current_index, 0);
    }
}

static inline void TEMPLATE(downheap_compare, T)(T *array, int64_t count, int64_t root_index, int (*compare)(T, T))
{
    int64_t largest_index = root_index;
    int64_t left_index = root_index * 2 + 1;
    int64_t right_index = root_index * 2 + 2;

    if (left_index < count && array[left_index] > array[largest_index])
    {
        largest_index = left_index;
    }

    if (right_index < count && array[right_index] > array[largest_index])
    {
        largest_index = right_index;
    }

    if (largest_index != root_index)
    {
        SWAP(array[largest_index], array[root_index], T);
        TEMPLATE(downheap_compare, T)(array, count, largest_index, compare);
    }
}

static inline void TEMPLATE(sort_compare_heap, T)(T *array, int64_t count, int (*compare)(T, T))
{
    // Building max heap
    for (int64_t root_index = count / 2 - 1; root_index >= 0; root_index--)
    {
        TEMPLATE(downheap_compare, T)(array, count, root_index, compare);
    }

    // Sorting
    for (int64_t current_index = count - 1; current_index >= 0; current_index--)
    {
        SWAP(array[0], array[current_index], T);
        TEMPLATE(downheap_compare, T)(array, current_index, 0, compare);
    }
}

#undef SWAP
#undef T
