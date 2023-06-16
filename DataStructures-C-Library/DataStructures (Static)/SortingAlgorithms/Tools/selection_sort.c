#ifndef SELECTION_SORT_C
#define SELECTION_SORT_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./Types/common_sorting.c"

// Sorts array by selecting minimums and placing them at start
void selection_sort(int A[], int size)
{
    for (int i = 0, min; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i)
            swap(A, i, min);
    }
} // time complexity = O( n^2 )

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif