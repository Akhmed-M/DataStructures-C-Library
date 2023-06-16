#ifndef INT_HEAP_H
#define INT_HEAP_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef int heapElement;

heapElement create_heapElement(heapElement e)
{
    return e;
}

int compare_heapElements(heapElement e1, heapElement e2)
{
    if (e1 == e2)
        return 0;
    return (e1 > e2) ? 1 : -1;
}

void print_heapElement(heapElement e)
{
    printf("%d ", e);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif