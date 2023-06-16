#ifndef TYPE_DLL_H
#define TYPE_DLL_H

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#include "../../Types(variable)/Int_LL.h"
// #include "../../Types(variables)/Char_LL.h"
// #include "../../Types(variables)/IntArray_LL.h"
// #include "../../Types(variables)/CharArray_LL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct DLL_Node
{
    listElement data;
    struct DLL_Node *next, *prev;
} DLL_Node, *DoublyLinkedList;

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#endif