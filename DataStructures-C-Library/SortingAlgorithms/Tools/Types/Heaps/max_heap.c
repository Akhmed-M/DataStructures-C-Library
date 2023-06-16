#ifndef MAX_HEAP_C
#define MAX_HEAP_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
// IMPORTS

#include "./Type/heap.h"
#include "./Type/common_heap.c"
#include <stdbool.h>

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
// PROTO-TYPES

bool heapifyDown_maxHeap(Heap H, int index);
bool heapifyUp_maxHeap(Heap H, int index);
bool Heapify_maxHeap(Heap H);

bool delete_max(Heap *H);
bool insert_maxHeap(Heap *H, heapElement newheapElement);

Heap *build_maxHeap(heapElement *Array, int size);

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

bool get_max(Heap H, heapElement *result)
{
    if (H.count == 0 || is_minHeap(H))
        return false; // empty heap OR invalid input
    *result = create_heapElement(H.h[0]);
    return true;
}

// Deletes max element in a max-heap (deletes root)
bool delete_max(Heap *H)
{
    if (H->count == 0 || is_minHeap(*H))
        return false; // already empty OR invalid input
    swap_heapElements(H->h, 0, H->count-- - 1);
    return heapifyDown_maxHeap(*H, 0);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

// Moves up an existing heapElement, to its correct position
bool heapifyUp_maxHeap(Heap H, int index)
{
    if (index <= 0 || index >= H.count || is_minHeap(H))
        return false; // index out of range

    int parent_i = indexOf_parent(H, index);
    if (compare_heapElements(H.h[index], H.h[parent_i]) <= 0)
        return true; // max property satisfied

    swap_heapElements(H.h, index, parent_i);
    return heapifyUp_maxHeap(H, parent_i);
}

// Moves down an existing heapElement, to its correct position
bool heapifyDown_maxHeap(Heap H, int index)
{
    if (index < 0 || index >= H.count || is_minHeap(H))
        return false; // index out of range

    int maxChild_i = indexOf_maxChild(H, index);
    if (maxChild_i == -1)
        return false; // has no children

    if (compare_heapElements(H.h[index], H.h[maxChild_i]) >= 0)
        return true; // max property satisfied

    swap_heapElements(H.h, index, maxChild_i);
    return heapifyDown_maxHeap(H, maxChild_i);
}

// Inserts a new heapElement in a heap (sorted according to property of a max-heap)
bool insert_maxHeap(Heap *H, heapElement newElement)
{
    if (!H || is_minHeap(*H))
        return false; // wrong input
    if (H->count == H->capacity)
        resize_heap(H);
    H->h[H->count++] = create_heapElement(newElement);
    return heapifyUp_maxHeap(*H, H->count - 1);
} // time complexity = O( n*log(n) )

// Sorts a heap into correct order (according to property of a max-heap)
bool Heapify_maxHeap(Heap H)
{
    if (H.count < 0 || is_minHeap(H))
        return false;
    int i = indexOf_parent(H, H.count - 1);
    for (; i >= 0; i--)
        heapifyDown_maxHeap(H, i);
    return true;
}

// Turns any array into a heap (sorted according to property of a max-heap)
Heap *build_maxHeap(heapElement *Array, int size)
{
    if (!Array || size <= 0)
        return NULL;
    Heap *newHeap = CreateHeap(size, 1); // 1 for max-heap

    // fill new heap (unordered)
    // for (int i = 0; i < size; i++)
    //     newHeap->h[i] = Array[i];
    newHeap->h = Array;
    newHeap->count = size;

    Heapify_maxHeap(*newHeap);
    return newHeap;
} // time complexity = O(n)

// Turns a given array into a heap (sorted according to property of a max-heap)
Heap *turnArrayInto_maxHeap(heapElement *Array, int size)
{
    if (!Array || size <= 0)
        return NULL;
    Heap *newHeap = CreateHeap(size, 1); // 1 for max-heap

    newHeap->h = Array;
    newHeap->count = newHeap->capacity = size;

    Heapify_maxHeap(*newHeap);
    return newHeap;
} // time complexity = O(n)

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif