#ifndef CharArray_LL_H
#define CharArray_LL_H

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *listElement;

listElement create_listElement(listElement e)
{
    listElement newE = (char *)malloc(sizeof(char) * strlen(e));
    strcpy(newE, e);
    return newE;
}

void print_listElement(listElement e)
{
    printf("%s ", e);
}

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#endif