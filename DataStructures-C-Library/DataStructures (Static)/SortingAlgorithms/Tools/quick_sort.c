#ifndef QUICK_SORT_C
#define QUICK_SORT_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./Types/common_sorting.c"

int partition_2(int A[], int low, int high)
{
    int leftWall = low;
    int rightWall = high - 1;
    do
    {
        while (leftWall <= rightWall && A[leftWall] <= A[high])
            leftWall++;
        while (leftWall <= rightWall && A[rightWall] > A[high])
            rightWall--;
        if (leftWall < rightWall)
            swap(A, leftWall++, rightWall--);
    } while (leftWall <= rightWall);
    swap(A, leftWall, high);
    return leftWall;
    // in the sub-while-loops we let leftWall<=rightWall
    // to make sure at the end we will swap pivot with something bigger than it
}

// Chooses a pivot and places it in its correct sorted position
int partition(int A[], int low, int high)
{
    int pivot = high;
    int i = low - 1;
    for (int j = low; j < high; j++)
        if (A[j] <= A[pivot] && ++i != j) // i!=j to eliminate unneccesary swaps
            swap(A, i, j);
    swap(A, i + 1, high); // move pivot to correct position
    return i + 1;
}

// average time complexity = O( n*log(n) )
// worst time complexity = O( n^2 )
void quick_sort_rec(int A[], int low, int high)
{
    if (low >= high)
        return;
    // int pivot = partition_2(A, low, high);
    int pivot = partition(A, low, high);
    quick_sort_rec(A, low, pivot - 1);
    quick_sort_rec(A, pivot + 1, high);
}

void quick_sort(int A[], int size)
{
    return quick_sort_rec(A, 0, size - 1);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif