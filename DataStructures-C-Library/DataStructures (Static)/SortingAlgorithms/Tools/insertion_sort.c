#ifndef INSERTION_SORT_C
#define INSERTION_SORT_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./Types/common_sorting.c"

void insertion_sort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && A[j - 1] > A[j])
        {
            swap(A, j - 1, j);
            j--;
        }
    }
} // time complexity = O( n^2 )

// version 2 (reduced swapping)
void insertion_sort_2(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int v = A[i];
        int j = i;
        while (j > 0 && A[j - 1] > v)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = v;
    }
} // time complexity = O( n^2 )

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif