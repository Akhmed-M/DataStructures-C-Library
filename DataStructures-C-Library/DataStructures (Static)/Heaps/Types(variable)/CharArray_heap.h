#ifndef CHAR_HEAP_H
#define CHAR_HEAP_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *heapElement;

heapElement create_heapElement(heapElement e)
{
    if (e == NULL)
        return NULL;
    char *newE = (char *)malloc(sizeof(char) * strlen(e));
    strcpy(newE, e);
    return newE;
}

int compare_heapElements(heapElement e1, heapElement e2)
{
    return strcmp(e1, e2);
}

void print_heapElement(heapElement e)
{
    printf("%s ", e);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif