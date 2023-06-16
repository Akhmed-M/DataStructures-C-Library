#ifndef INTARRAY_LL_H
#define INTARRAY_LL_H

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef int *listElement;

listElement create_listElement(listElement e)
{
    int size = sizeof(e) / sizeof(e[0]);
    int *newE = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        newE[i] = e[i];
    return newE;
}

void print_listElement(listElement e)
{
    int size = sizeof(e) / sizeof(e[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", e[i]);
}

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#endif