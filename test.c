#include <stdio.h>
#include <stdlib.h>

#define T int
#include "inc/sort.h"

#define len(x) sizeof(x) / sizeof(*x)

int comp(int a, int b)
{
    return a - b;
}

int main()
{
    int arr[] = {4, 5, 2, 3, 9, 8, 4, 5, 10, 11, 99, 2, 7, 54, 2, -3, -45, -223, 4, -8, 44, 0};
    sort_compare_quick_int(arr, len(arr), comp);

    for(size_t i = 0; i < len(arr); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}