#ifndef DELETE_DLL_C
#define DELETE_DLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "../Type_DLL.h"

// PROTO-TYPES

void Delete_DLL(DLL_Node **headPtr);
void DeleteHead_DLL(DLL_Node **headPtr);
void DeleteTail_DLL(DLL_Node **headPtr);

void DeletePos0_DLL(DLL_Node **headPtr, int pos); // Starting from index 0
void DeletePos1_DLL(DLL_Node **headPtr, int pos); // Starting from index 1

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

void DeleteHead_DLL(DLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    DLL_Node *head = *headPtr;
    if (head->next)
        head->next->prev = head->prev;
    (*headPtr) = (*headPtr)->next;
    free(head);
}

void Delete_DLL(DLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    DeleteHead_DLL(headPtr);
    Delete_DLL(headPtr);
}

void DeleteTail_DLL(DLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    if ((*headPtr)->next == NULL)
        return DeleteHead_DLL(headPtr);
    DeleteTail_DLL(&((*headPtr)->next));
}

void DeletePos0_DLL(DLL_Node **headPtr, int pos) // Starting from index 0
{
    if (pos < 0)
        return;
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    if (pos == 0)
        return DeleteHead_DLL(headPtr);
    DeletePos0_DLL(&((*headPtr)->next), pos - 1);
}

void DeletePos1_DLL(DLL_Node **headPtr, int pos) // Starting from index 1
{
    if (pos <= 0)
        return;
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    if (pos == 1)
        return DeleteHead_DLL(headPtr);
    DeletePos1_DLL(&((*headPtr)->next), pos - 1);
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

#endif