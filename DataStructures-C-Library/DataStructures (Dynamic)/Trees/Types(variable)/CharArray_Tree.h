#ifndef CHARARRAY_TREE_H
#define CHARARRAY_TREE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TREE_PRINTFORMAT "%s "
typedef char *treeElement;

treeElement createTreeElement(treeElement e)
{
    if (e == NULL)
        return NULL;
    char *newE = (char *)malloc(sizeof(char) * strlen(e));
    strcpy(newE, e);
    return newE;
}

treeElement maxLimit_treeElement()
{
    return "\177"; // DEL (max ASCII code char)
}

treeElement minLimit_treeElement()
{
    return "\0"; // NULL (min ASCII code char)
}

int compareTreeElements(treeElement e1, treeElement e2)
{
    if (strcmp(e1, maxLimit_treeElement()) == 0 || strcmp(e2, minLimit_treeElement()) == 0)
        return 1;
    if (strcmp(e2, maxLimit_treeElement()) == 0 || strcmp(e1, minLimit_treeElement()) == 0)
        return -1;
    return strcmp(e1, e2);
}

void printTreeElement(treeElement e)
{
    printf(TREE_PRINTFORMAT, e);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif