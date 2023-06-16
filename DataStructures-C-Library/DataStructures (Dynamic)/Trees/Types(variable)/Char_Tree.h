#ifndef CHAR_TREE_H
#define CHAR_TREE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE_PRINTFORMAT "%c "
typedef char treeElement;

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
    return '\177'; // DEL (max ASCII code char)
}

treeElement minLimit_treeElement()
{
    return '\0'; // NULL (min ASCII code char)
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif