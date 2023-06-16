#ifndef HEAP_H
#define HEAP_H

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "../../../../Types(variable)/Int_sort.h"
// #include "./Types(variable)/Char_heap.h"
// #include "./Types(variable)/Char_Array_heap.h"

typedef sortElement heapElement;

typedef struct Heap
{
    heapElement *h;
    int count, capacity;
    int type; // minHeap=0 && maxHeap=1
} Heap;

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif
