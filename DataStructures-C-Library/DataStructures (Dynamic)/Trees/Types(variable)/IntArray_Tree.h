#ifndef INTARRAY_TREE_H
#define INTARRAY_TREE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int *treeElement;

treeElement createTreeElement(treeElement e)
{
    int size = sizeof(e) / sizeof(e[0]);
    int *newE = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        newE[i] = e[i];
    return newE;
}

// depends on the objective of the problem
int compareTreeElements(treeElement e1, treeElement e2)
{
}

void printTreeElement(treeElement e)
{
    int size = sizeof(e) / sizeof(e[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", e[i]);
}

treeElement maxLimit_treeElement()
{
}

treeElement minLimit_treeElement()
{
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif