#ifndef REVERSE_DLL_C
#define REVERSE_DLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "../Type_DLL.h"

// PROTO-TYPES

void ReverseList1_DLL(DLL_Node **headPtr);
void ReverseList2_DLL(DLL_Node **headPtr);

DLL_Node *ReverseList3_DLL(DLL_Node *head);
DLL_Node *ReverseList4_DLL(DLL_Node *head);

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// REVERSE

void ReverseList_DLL(DLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    DLL_Node *temp = (*headPtr)->next, *head = *headPtr;
    (*headPtr)->next = (*headPtr)->prev;
    (*headPtr)->prev = temp;

    (*headPtr) = temp;
    ReverseList_DLL(headPtr);
    if (temp == NULL)
        *headPtr = head;
} // Reverse from start to end

void ReverseList2_DLL(DLL_Node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    DLL_Node *head = *headPtr;
    (*headPtr) = (*headPtr)->next;
    ReverseList2_DLL(headPtr);

    // head->next = NULL
    DLL_Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if (temp == NULL)
        *headPtr = head;
} // Reverse from end to start

DLL_Node *ReverseList3_DLL(DLL_Node *head)
{
    if (head == NULL)
        return head;

    DLL_Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    DLL_Node *newHead = ReverseList3_DLL(head->prev);
    if (newHead == NULL)
        return head;
    return newHead;
} // Reverse from start to end

DLL_Node *ReverseList4_DLL(DLL_Node *head)
{
    if (head == NULL)
        return head;
    DLL_Node *newHead = ReverseList4_DLL(head->prev);

    DLL_Node *temp = head->next;
    head->next = head->prev;
    head->prev = temp;

    if (newHead == NULL)
        return head;
    return newHead;
} // Reverse from end to start

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
#endif