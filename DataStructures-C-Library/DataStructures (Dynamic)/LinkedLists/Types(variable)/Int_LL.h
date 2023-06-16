#ifndef INT_LL_H
#define INT_LL_H

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int listElement;

listElement create_listElement(listElement e)
{
    return e;
}

void print_listElement(listElement e)
{
    printf("%d ", e);
}

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#endif