#ifndef CHARARRAY_SORT_H
#define CHARARRAY_SORT_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *sortElement;

sortElement create_sortElement(sortElement e)
{
    char *newE = (char *)malloc(sizeof(char) * strlen(e));
    strcpy(newE, e);
    return newE;
}

int compare_sortElements(sortElement e1, sortElement e2)
{
    return strcmp(e1, e2);
}

void print_sortElement(sortElement e)
{
    printf("%s ", e);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif