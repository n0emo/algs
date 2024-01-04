
#ifndef T
#error Template parameter T was not defined.
#endif

#include<stdint.h>

#include "template.h"

// Return the index of an element, if array contains it;
// -1 otherwise.
int64_t TEMPLATE(binary_search, T)(T *array, int64_t count, T element)
{
    if(array == NULL || count <= 0)
    {
        return -1;
    }

    int64_t left_index = 0;
    int64_t right_index = count - 1;

    while(left_index <= right_index)
    {
        int64_t middle_index = (right_index + left_index) / 2;
        T middle = array[middle_index];
        if(element > middle)
        {
            left_index = middle_index + 1; 
        }
        else if(element < middle)
        {
            right_index = middle_index - 1;
        }
        else
        {
            return middle_index;
        }
    }
    
    return -1;
}