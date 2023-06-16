#ifndef BASICFUNCTIONS_SLL_C
#define BASICFUNCTIONS_SLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "./Type_SLL.h"

// PROTO-TYPES

int size_SLL(SLL_Node *head);
int PrintList_SLL(SLL_Node *head);

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

int size_SLL(SLL_Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + size(head->next);
}

// Prints list && Returns its length
int PrintList_SLL(SLL_Node *head)
{
    if (head == NULL)
    {
        printf("\nList is either Empty OR Printed!\n");
        return 0;
    }
    print_listElement(head->data);
    return 1 + PrintList_SLL(head->next);
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#endif