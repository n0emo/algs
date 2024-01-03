#include <stdio.h>
#include <stdlib.h>
#include "sort/sort.h"

int comp(int a, int b)
{
    return b - a;
}

int main()
{
    int arr[] = {4, 5, 2, 3, 9, 8, 4, 5, 10, 11};
    sort_compare_bubble(arr, 10, comp);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}