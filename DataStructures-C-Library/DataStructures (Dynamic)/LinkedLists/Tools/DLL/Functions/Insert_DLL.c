#ifndef INSERT_DLL_C
#define INSERT_DLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "../Type_DLL.h"

// PROTO-TYPES
void InsertHead_DLL(DLL_Node **headPtr, listElement data);
void InsertTail_DLL(DLL_Node **headPtr, listElement data);

void InsertPos0_DLL(DLL_Node **headPtr, listElement data, int pos);
void InsertPos1_DLL(DLL_Node **headPtr, listElement data, int pos);

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

void InsertHead_DLL(DLL_Node **headPtr, listElement data)
{
    if (headPtr == NULL)
        return;
    DLL_Node *newDLL_Node = (DLL_Node *)malloc(sizeof(DLL_Node));
    newDLL_Node->data = create_listElement(data);
    newDLL_Node->prev = NULL;
    if (*headPtr)
    {
        newDLL_Node->prev = (*headPtr)->prev;
        (*headPtr)->prev = newDLL_Node;
    }
    newDLL_Node->next = *headPtr;
    *headPtr = newDLL_Node;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

void InsertTail_DLL_helper(DLL_Node **headPtr, listElement data, DLL_Node *prev)
{
    if (headPtr == NULL)
        return;
    if (*headPtr == NULL)
    {
        InsertHead_DLL(headPtr, data);
        (*headPtr)->prev = prev;
        return;
    }
    InsertTail_DLL_helper(&((*headPtr)->next), data, *headPtr);
}

void InsertTail_DLL(DLL_Node **headPtr, listElement data)
{
    InsertTail_DLL_helper(headPtr, data, NULL); // Initializes prev to NULL
} // This function initializes 3th parameter "prev" so that we do not have to do it inside of "Library-Test.c"
// This way "Library-Test.c" can be a multi-use code

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

void InsertPos0_DLL_helper(DLL_Node **headPtr, listElement data, int pos, DLL_Node *prev) // Starting from index 0
{                                                                                         // Initially prev=NULL
    if (pos < 0 || headPtr == NULL)
        return;
    if ((*headPtr) == NULL && pos > 0)
        return;
    if (pos == 0)
    {
        InsertHead_DLL(headPtr, data);
        (*headPtr)->prev = prev;
        return;
    }
    InsertPos0_DLL_helper(&((*headPtr)->next), data, pos - 1, *headPtr);
} // if pos=length ==> Appends new tail | if pos<length appends | if pos>length returns

void InsertPos0_DLL(DLL_Node **headPtr, listElement data, int pos) // Doesn't have "prev" parameter
{
    InsertPos0_DLL_helper(headPtr, data, pos, NULL); // Initializes prev to NULL
} // This function initializes 4th parameter "prev" so that we do not have to do it inside of "Library-Test.c"
// This way "Library-Test.c" can be a multi-use code

void InsertPos1_DLL_helper(DLL_Node **headPtr, listElement data, int pos, DLL_Node *prev) // Starting from index 1
{                                                                                         // Initially prev=NULL
    if (pos <= 0 || headPtr == NULL)
        return;
    if ((*headPtr) == NULL && pos > 1)
        return;
    if (pos == 1)
    {
        InsertHead_DLL(headPtr, data);
        (*headPtr)->prev = prev;
        return;
    }
    InsertPos1_DLL_helper(&((*headPtr)->next), data, pos - 1, *headPtr);
} // if pos=length+1 ==> Appends new tail | if pos<=length appends | if pos>length+1 returns

void InsertPos1_DLL(DLL_Node **headPtr, listElement data, int pos)
{
    InsertPos1_DLL_helper(headPtr, data, pos, NULL); // Initializes prev
} // This function initializes 4th parameter "prev" so that we do not have to do it inside of "Library-Test.c"
// This way "Library-Test.c" can be a multi-use code

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

#endif