#ifndef INTARRAY_DS_H
#define INTARRAY_DS_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int *DS_element;

DS_element create_DS_element(DS_element e)
{
    int size = sizeof(e) / sizeof(e[0]);
    int *newE = (int *)malloc(sizeof(int) * size); // allocate
    for (int i = 0; i < size; i++)                 // fill content
        newE[i] = e[i];
    return newE;
}

void print_DS_element(DS_element e)
{
    int size = sizeof(e) / sizeof(e[0]);
    for (int i = 0; i < size; i++)
        printf("%d ", e[i]);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#endif