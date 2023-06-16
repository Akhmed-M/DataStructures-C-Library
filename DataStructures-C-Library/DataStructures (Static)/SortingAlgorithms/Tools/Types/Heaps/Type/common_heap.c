#ifndef COMMON_HEAP_C
#define COMMON_HEAP_C

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
#include "./heap.h"
#include <stdbool.h>

// PROTO-TYPES

Heap *CreateHeap(int capacity, int type);
bool resize_heap(Heap *H);
bool destory_heap(Heap **H);

bool is_minHeap(Heap H);
bool is_maxHeap(Heap H);

void swap_heapElements(heapElement A[], int i, int j);

int indexOf_parent(Heap H, int index);
int indexOf_leftChild(Heap H, int index);
int indexOf_rightChild(Heap H, int index);
int indexOf_maxChild(Heap H, int index);
int indexOf_minChild(Heap H, int index);

void print_heap(Heap H);
void print_heap_withChildren(Heap H);

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/
// CREATE-RESIZE-DESTROY

// Creates a new heap with a given capacity (default capacity = 1)
Heap *CreateHeap(int capacity, int type)
{
    if (capacity <= 0)
        capacity = 1;
    Heap *H = (Heap *)malloc(sizeof(Heap));
    H->h = (heapElement *)malloc(sizeof(heapElement) * capacity);
    H->capacity = capacity;
    H->type = type;
    H->count = 0;
    return H;
}

// Doubles the size of a heap
bool resize_heap(Heap *H)
{
    if (H == NULL)
        return false; // invalid input
    H->capacity *= 2;
    heapElement *temp = H->h;
    H->h = (heapElement *)malloc(sizeof(heapElement) * H->capacity);
    for (int i = 0; i < H->count; i++)
        H->h[i] = temp[i];
    free(temp);
    return true;
}

// Deletes a heap
bool destory_heap(Heap **H)
{
    if (!H || !(*H))
        return false; // wrong input
    free((*H)->h);
    free(*H);
    *H = NULL;
    return true;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

bool is_minHeap(Heap H)
{
    return H.type == 0;
}
bool is_maxHeap(Heap H)
{
    return H.type == 1;
}

// swap two elements in an array
void swap_heapElements(heapElement A[], int i, int j)
{
    heapElement temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Returns index of parent node
int indexOf_parent(Heap H, int index)
{
    if (index <= 0 || H.count == 0)
        return -1;
    return (index - 1) / 2;
}

// Returns index of left-child node
int indexOf_leftChild(Heap H, int index)
{
    if (index < 0 || H.count == 0)
        return -1;
    int result = 2 * index + 1;
    if (result >= H.count)
        return -1;
    return result;
}

// Returns index of right-child node
int indexOf_rightChild(Heap H, int index)
{
    if (index < 0 || index >= H.count || H.count == 0)
        return -1; // index out of range
    int result = 2 * index + 2;
    if (result >= H.count)
        return -1;
    return result;
}

// Returns the index of the child node with the maximum value
// If the given index is out of range or has no children, returns -1
int indexOf_maxChild(Heap H, int index)
{
    if (index < 0 || index >= H.count)
        return -1; // index out of range

    int leftChild_i = indexOf_leftChild(H, index);
    if (leftChild_i == -1)
        return -1; // has no children

    int rightChild_i = indexOf_rightChild(H, index);
    if (rightChild_i == -1)
        return leftChild_i; // has only left child

    // Return index of max child
    if (H.h[leftChild_i] > H.h[rightChild_i])
        return leftChild_i;
    return rightChild_i;
}

// Returns the index of the child node with the min value
// If the given index is out of range or has no children, returns -1
int indexOf_minChild(Heap H, int index)
{
    if (index < 0 || index >= H.count)
        return -1; // index out of range

    int leftChild_i = indexOf_leftChild(H, index);
    if (leftChild_i == -1)
        return -1; // has no children

    int rightChild_i = indexOf_rightChild(H, index);
    if (rightChild_i == -1)
        return leftChild_i; // has only left child

    // Return index of max child
    if (H.h[leftChild_i] > H.h[rightChild_i])
        return leftChild_i;
    return rightChild_i;
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

void print_heap(Heap H)
{
    for (int i = 0; i < H.count; i++)
        printf("%d ", H.h[i]);
    printf("\n");
}

void print_heap_withChildren(Heap H)
{
    printf("\n");
    int leftChild_i, rightChild_i;
    for (int i = 0; i < H.count; i++)
    {
        leftChild_i = indexOf_leftChild(H, i);
        rightChild_i = indexOf_rightChild(H, i);
        if (leftChild_i == -1)
        {
            printf("%d (no children)\n", H.h[i]);
            continue;
        }
        if (rightChild_i == -1)
            printf("%d (leftChild=%d)\n", H.h[i], H.h[leftChild_i]);
        else
            printf("%d (leftChild=%d & rightChild=%d)\n", H.h[i], H.h[leftChild_i], H.h[rightChild_i]);
    }
    printf("\n");
}

/*-----------------------------------------------------------------*/
/*-----------------------------------------------------------------*/

#endif