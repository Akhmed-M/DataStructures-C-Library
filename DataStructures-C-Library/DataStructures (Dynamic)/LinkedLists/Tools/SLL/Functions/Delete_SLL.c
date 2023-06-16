#ifndef DELETE_SLL_C
#define DELETE_SLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "../Type_SLL.h"

// PROTO-TYPES

void DeleteHead_SLL(SLL_Node **headPtr);
void DeleteTail_SLL(SLL_Node **headPtr);
void DeleteList_SLL(SLL_Node **headPtr);

void DeletePos0_SLL(SLL_Node **headPtr, int pos);
void DeletePos1_SLL(SLL_Node **headPtr, int pos);

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

void DeleteHead_SLL(SLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    SLL_Node *head = *headPtr;
    (*headPtr) = (*headPtr)->next;
    free(head);
}

void DeleteList_SLL(SLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    DeleteHead_SLL(headPtr);
    DeleteList_SLL(headPtr);
}

void DeleteTail_SLL(SLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    if ((*headPtr)->next == NULL)
        return DeleteHead_SLL(headPtr);
    DeleteTail_SLL(&((*headPtr)->next));
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

// Deletes a node at a certain position (starting from index 0)
void DeletePos0_SLL(SLL_Node **headPtr, int pos)
{
    if (pos < 0)
        return;
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    if (pos == 0)
        return DeleteHead_SLL(headPtr);
    DeletePos0_SLL(&((*headPtr)->next), pos - 1);
}

// Deletes a node at a certain position (starting from index 1)
void DeletePos1_SLL(SLL_Node **headPtr, int pos)
{
    if (pos <= 0)
        return;
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    if (pos == 1)
        return DeleteHead_SLL(headPtr);
    DeletePos1_SLL(&((*headPtr)->next), pos - 1);
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

#endif