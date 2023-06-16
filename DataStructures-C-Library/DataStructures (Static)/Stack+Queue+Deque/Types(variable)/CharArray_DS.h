#ifndef CHARARRAY_DS_H
#define CHARARRAY_DS_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char *DS_element;

DS_element create_DS_element(DS_element e)
{
    if (e == NULL)
        return NULL;
    char *newE = (char *)malloc(sizeof(char) * strlen(e));
    strcpy(newE, e);
    return newE;
}

void print_DS_element(DS_element e)
{
    printf("%s ", e);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif