#ifndef INT_TREE_H
#define INT_TREE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TREE_PRINTFORMAT "%d "

typedef int treeElement;

treeElement createTreeElement(treeElement e)
{
    return e;
}

int compareTreeElements(treeElement e1, treeElement e2)
{
    if (e1 == e2)
        return 0;
    return (e1 > e2) ? 1 : -1;
}

void printTreeElement(treeElement e)
{
    printf(TREE_PRINTFORMAT, e);
}

treeElement maxLimit_treeElement()
{
    return INT_MAX;
}

treeElement minLimit_treeElement()
{
    return INT_MIN;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif