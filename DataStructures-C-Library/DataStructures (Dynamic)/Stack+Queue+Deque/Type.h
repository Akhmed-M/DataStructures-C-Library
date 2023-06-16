#ifndef TYPE_H
#define TYPE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include "./Types(variable)/Int_DS.h"
// #include "./Types(variable)/Char_DS.h"
// #include "./Types(variable)/IntArray_DS.h"
// #include "./Types(variable)/CharArray_DS.h"

typedef struct cell
{
    DS_element data;
    struct cell *next;
} cell;

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

#endif