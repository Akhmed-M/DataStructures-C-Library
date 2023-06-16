#ifndef COMMON_SORTING_C
#define COMMON_SORTING_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#include <stdio.h>

void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void print_array(int A[], int size)
{
    if (size <= 0)
        return;
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif