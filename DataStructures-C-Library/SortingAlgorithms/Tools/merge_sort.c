#ifndef INSERTION_SORT_C
#define INSERTION_SORT_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./Types/common_sorting.c"

// Merges two sorted arrays 'left' and 'right' into a single sorted array
void merge(int left[], int leftSize, int right[], int rightSize, int merged[])
{
    int i, j, k;
    i = j = k = 0;

    while (i < leftSize && j < rightSize)
        if (left[i] < right[j])
            merged[k++] = left[i++];
        else
            merged[k++] = right[j++];

    while (i < leftSize)
        merged[k++] = left[i++];
    while (j < rightSize)
        merged[k++] = right[j++];
}

void merge_sort(int A[], int size)
{
    if (size == 1)
        return; // already sorted (can not split into sub-arrays)

    // create sub-arrays
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // fill sub-arrays
    int i;
    for (i = 0; i < mid; i++)
        left[i] = A[i];
    for (; i < size; i++)
        right[i - mid] = A[i];

    // divide sub-arrays into smaller sub-arrays
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // merge sub-arrays
    merge(left, mid, right, size - mid, A);
} // time complexity = O( n*log(n) )

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif