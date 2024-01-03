#include <stdio.h>
#include <stdlib.h>
#include "sort/sort.h"

int main()
{
    int arr[] = {4, 5, 2, 3, 9, 8, 4, 5, 10, 11};
    sort_bubble(arr, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}