#ifndef INSERT_SLL_C
#define INSERT_SLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "../Type_SLL.h"

// PROTO-TYPES

void InsertHead_SLL(SLL_Node **headPtr, listElement data);
void InsertTail_SLL(SLL_Node **headPtr, listElement data);

void InsertPos0_SLL(SLL_Node **headPtr, listElement data, int pos);
void InsertPos1_SLL(SLL_Node **headPtr, listElement data, int pos);

void InsertPos0_SLL_2(SLL_Node **headPtr, listElement data, int pos);
void InsertPos1_SLL_2(SLL_Node **headPtr, listElement data, int pos);

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

void InsertHead_SLL(SLL_Node **headPtr, listElement data)
{
    if (headPtr == NULL)
        return;
    SLL_Node *newNode = (SLL_Node *)malloc(sizeof(SLL_Node));
    newNode->data = create_listElement(data);

    newNode->next = *headPtr;
    *headPtr = newNode;
}

void InsertTail_SLL(SLL_Node **headPtr, listElement data)
{
    if (headPtr == NULL)
        return;
    if ((*headPtr) == NULL)
        return InsertHead_SLL(headPtr, data);
    InsertTail_SLL(&((*headPtr)->next), data);
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

// Inserts new node at certain position (starting from index 0)
// Range: pos=[0,length]
void InsertPos0_SLL(SLL_Node **headPtr, listElement data, int pos)
{
    if (pos < 0 || headPtr == NULL)
        return;
    if ((*headPtr) == NULL && pos > 0)
        return;
    if (pos == 0)
        return InsertHead_SLL(headPtr, data);
    InsertPos0_SLL(&((*headPtr)->next), data, pos - 1);
} // if pos=length ==> Appends new tail | if pos<length appends | if pos>length returns

// Inserts new node at certain position (starting from index 1)
// Range: pos=[1, length+1]
void InsertPos1_SLL(SLL_Node **headPtr, listElement data, int pos)
{
    if (pos <= 0 || headPtr == NULL) // Changed <0 to <=0
        return;
    if ((*headPtr) == NULL && pos > 1) // Changed 0 to 1
        return;
    if (pos == 1) // Changed 0 to 1
        return InsertHead_SLL(headPtr, data);
    InsertPos1_SLL(&((*headPtr)->next), data, pos - 1);
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
// 2nd Versions

// Second version of `InsertPos0_SLL` function
// Range: pos=[1, +inf] (appends new tail if pos>=length)
void InsertPos0_SLL_2(SLL_Node **headPtr, listElement data, int pos)
{
    if (pos < 0 || headPtr == NULL)
        return;
    if (pos == 0 || (*headPtr) == NULL)
        return InsertHead_SLL(headPtr, data);
    InsertPos0_SLL_2(&((*headPtr)->next), data, pos - 1);
}

// Second version of `InsertPos1_SLL` function
// Range: pos=[1, +inf] (appends new tail if pos>=length+1)
void InsertPos1_SLL_2(SLL_Node **headPtr, listElement data, int pos)
{
    if (pos <= 0 || headPtr == NULL) // Changed <0 to <=0
        return;
    if (pos == 1 || (*headPtr) == NULL) // Changed 0 to 1
        return InsertHead_SLL(headPtr, data);
    InsertPos1_SLL_2(&((*headPtr)->next), data, pos - 1);
}

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

#endif