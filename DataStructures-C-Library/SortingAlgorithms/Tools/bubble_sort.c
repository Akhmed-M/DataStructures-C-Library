#ifndef BUBBLE_SORT_C
#define BUBBLE_SORT_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./Types/common_sorting.c"

// Sorts an array by bubbling maxs to the far right
// Improved version of bubble sort (minimal iterations + already sorted check)
void bubble_sort_improved(int A[], int size)
{
    if (size <= 0)
        return;
    int swapped = 1;
    int last = size - 1;
    for (; last > 0 && swapped; last--)
    {
        swapped = 0;
        for (int i = 0; i < last; i++)
            if (A[i] > A[i + 1])
            {
                swap(A, i, i + 1);
                swapped = 1;
            }
    }
} // time complexity = O( n^2 )

void bubble_sort(int A[], int size)
{
    if (size <= 0)
        return;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (A[j] > A[j + 1])
                swap(A, j, j + 1);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif