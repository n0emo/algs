#ifndef SWAP
#define SWAP(a, b, T) do { T tmp = a; a = b; b = tmp; } while(0) 
#endif
#ifdef T
#include <stdio.h>
#include "../template.h"


void TEMPLATE(sort_bubble, T)(T *array, int count)
{
    for(int i = 0; i < count; i++)
    {
        for(int j = i + 1; j < count; j++)
        {
            if(array[i] > array[j])
            {
                SWAP(array[i], array[j], T);
            }
        }
    }
}

#endif