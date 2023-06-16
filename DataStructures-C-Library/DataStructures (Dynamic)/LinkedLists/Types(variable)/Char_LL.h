#ifndef CHAR_LL_H
#define CHAR_LL_H

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef char listElement;

listElement create_listElement(listElement e)
{
    return e;
}

void print_listElement(listElement e)
{
    printf("%c ", e);
}

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#endif