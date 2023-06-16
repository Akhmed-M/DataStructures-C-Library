#ifndef HEAP_SORT_C
#define HEAP_SORT_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./Types/common_sorting.c"
#include "./Types/Heaps/max_heap.c"

void heap_sort(int A[], int size)
{
    if (size <= 0)
        return;
    Heap *H = turnArrayInto_maxHeap(A, size);

    for (int i = size - 1; i; i--)
    {
        // Place max at end
        swap(A, 0, i);
        H->count--;
        heapifyDown_maxHeap(*H, 0);
    }
} // time complexity = O( n*log(n) )

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif