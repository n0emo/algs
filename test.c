#include <stdio.h>
#include <stdlib.h>

#define T int
#include "inc/sort.h"

int comp(int a, int b)
{
    return a - b;
}

int main()
{
    int arr[] = {4, 5, 2, 3, 9, 8, 4, 5, 10, 11};
    sort_bubble_int(arr, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}