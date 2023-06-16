#ifndef TYPE_SLL_H
#define TYPE_SLL_H

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#include "../../Types(variable)/Int_LL.h"
// #include "../../Types(variables)/Char_LL.h"
// #include "../../Types(variables)/IntArray_LL.h"
// #include "../../Types(variables)/CharArray_LL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct SLL_Node
{
    listElement data;
    struct SLL_Node *next;
} SLL_Node, *SinglyLinkedList;

/*---------------------------------------------------------*/
/*---------------------------------------------------------*/

#endif