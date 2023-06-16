#ifndef REVERSE_SLL_C
#define REVERSE_SLL_C

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#include "../Type_SLL.h"

// PROTO-TYPES

void ReverseList_SLL(SLL_Node **headRef);
SLL_Node *ReverseList2_SLL(SLL_Node *head);
SLL_Node *ReverseList3_SLL(SLL_Node *head);

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/

void ReverseList_SLL(SLL_Node **headRef)
{
    if ((*headRef) == NULL || (*headRef)->next == NULL) // Empty OR 1 node
        return;

    SLL_Node *prev = *headRef;
    *headRef = prev->next; // current
    ReverseList_SLL(headRef);

    SLL_Node *temp = (prev->next)->next;
    (prev->next)->next = prev;
    prev->next = temp;
}

SLL_Node *ReverseList2_SLL(SLL_Node *head)
{
    if (head == NULL || head->next == NULL) // Empty OR only 1 node exists
        return head;
    SLL_Node *newHead = ReverseList2_SLL(head->next);
    (head->next)->next = head;
    head->next = NULL;
    return newHead;
}

SLL_Node *ReverseList3_SLL_helper(SLL_Node *prev, SLL_Node *current, SLL_Node *next)
{
    current->next = prev;
    if (current == NULL || next == NULL)
        return current;
    return ReverseList3_SLL_helper(current, next, next->next);
} // Initially: prev=NULL current=head next=head->next

SLL_Node *ReverseList3_SLL(SLL_Node *head)
{
    return ReverseList3_SLL_helper(NULL, head, head->next);
} // Initializes ReverseList3_SLL_helper arguments

/*------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------*/
#endif