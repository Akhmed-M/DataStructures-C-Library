#ifndef MIN_HEAP_C
#define MIN_HEAP_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
// IMPORTS

#include "./Type/heap.h"
#include "./Type/common_heap.c"
#include <stdbool.h>

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
// PROTO-TYPES

bool heapifyDown_minHeap(Heap H, int index);
bool heapifyUp_minHeap(Heap H, int index);
bool Heapify_minHeap(Heap H);

bool delete_min(Heap *H);
bool insert_minHeap(Heap *H, heapElement newheapElement);

Heap *build_minHeap(heapElement *Array, int size);

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

bool get_min(Heap H, heapElement *result)
{
    if (H.count == 0 || is_maxHeap(H))
        return false; // empty or wrong input
    *result = create_heapElement(H.h[0]);
    return true;
}

// Deletes max heapElement in the heap (root)
bool delete_min(Heap *H)
{
    if (H->count == 0 || is_maxHeap(*H))
        return false; // already empty
    swap_heapElements(H->h, 0, H->count-- - 1);
    return heapifyDown_minHeap(*H, 0);
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

// Moves up an existing heapElement, to its correct position
bool heapifyUp_minHeap(Heap H, int index)
{
    if (index <= 0 || index >= H.count || is_maxHeap(H))
        return false; // index out of range

    int parent_i = indexOf_parent(H, index);
    if (compare_heapElements(H.h[parent_i], H.h[index]) <= 0)
        return true; // max property satisfied

    swap_heapElements(H.h, index, parent_i);
    return heapifyUp_minHeap(H, parent_i);
}

// Moves down an existing heapElement, to its correct position
bool heapifyDown_minHeap(Heap H, int index)
{
    if (index < 0 || index >= H.count || is_maxHeap(H))
        return false; // index out of range

    // get min child
    int minChild_i = indexOf_minChild(H, index);
    if (minChild_i == -1)
        return false; // has no children

    // if parent < both children
    if (compare_heapElements(H.h[index], H.h[minChild_i]) <= 0)
        return true; // min property satisfied

    swap_heapElements(H.h, index, minChild_i);
    return heapifyDown_minHeap(H, minChild_i);
}

// Inserts a new heapElement in a heap (sorted according to property of a min-heap)
bool insert_minHeap(Heap *H, heapElement newElement)
{
    if (!H || is_maxHeap(*H))
        return false; // wrong input
    if (compare_heapElements(H->count, H->capacity) == 0)
        resize_heap(H);
    H->h[H->count++] = create_heapElement(newElement);
    return heapifyUp_minHeap(*H, H->count - 1);
} // time complexity = O( n*log(n) )

// Sorts a heap into correct order (according to property of a max-heap)
bool Heapify_minHeap(Heap H)
{
    if (H.count < 0 || is_maxHeap(H))
        return false;
    int i = indexOf_parent(H, H.count - 1);
    for (; i >= 0; i--)
        heapifyDown_minHeap(H, i);
    return true;
}

// Returns a min-heap copy of a given array (sorted according to property of a min-heap)
Heap *build_minHeap(heapElement *Array, int size)
{
    if (!Array || size <= 0)
        return NULL;
    Heap *newHeap = CreateHeap(size, 0); // 0 for min-heap

    // fill new heap (unordered)
    for (int i = 0; i < size; i++)
        newHeap->h[i] = create_heapElement(Array[i]);
    newHeap->count = newHeap->capacity = size;

    Heapify_minHeap(*newHeap);
    return newHeap;
} // time complexity = O(n)

// Turns a given array into a heap (sorted according to property of a min-heap)
Heap *turnArrayInto_minHeap(heapElement *Array, int size)
{
    if (!Array || size <= 0)
        return NULL;
    Heap *newHeap = CreateHeap(size, 0); // 0 for min-heap

    newHeap->h = Array;
    newHeap->count = newHeap->capacity = size;

    Heapify_minHeap(*newHeap);
    return newHeap;
} // time complexity = O(n)

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif