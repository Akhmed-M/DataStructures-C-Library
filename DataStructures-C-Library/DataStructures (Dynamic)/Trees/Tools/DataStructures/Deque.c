#ifndef DEQUE_C
#define DEQUE_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
#include "Tree_Type.h"

typedef struct
{
    cell *front, *rear;
} deque;

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PUBLIC FUNCTIONS

deque CreateDeque()
{
    deque d;
    d.front = d.rear = NULL;
    return d;
}

int isEmptyDeque(deque q)
{
    return q.front == NULL;
}

// INSERT HEAD
int EnQueueFront(deque *d, DS_element data)
{
    cell *newHead = (cell *)malloc(sizeof(cell));
    if (!newHead)
        return 0; // MEMORY ERROR
    newHead->data = data;

    if (d->front == NULL)
        d->rear = newHead;
    newHead->next = d->front;
    d->front = newHead;
    return 1; // SUCCESS
}

// INSERT TAIL
int EnQueueRear(deque *d, DS_element data)
{
    cell *newTail = (cell *)malloc(sizeof(cell));
    if (!newTail)
        return 0; // MEMORY ERROR
    newTail->data = data;
    newTail->next = NULL;

    if (isEmptyDeque(*d))
        d->front = newTail;
    else
        d->rear->next = newTail;
    d->rear = newTail;

    return 1; // SUCCESS
}

// DELETE HEAD
int DeleteFront(deque *d)
{
    if (isEmptyDeque(*d))
        return 0; // NOTHING TO DELETE
    cell *head = d->front;
    (d->front) = (d->front)->next;
    head->next = NULL;
    free(head);

    if (d->front == NULL)
        d->rear = NULL;
    return 1;
}

// DELETE TAIL
int DeleteRear(deque *d)
{
    if (isEmptyDeque(*d))
        return 0; // NOTHING TO DELETE
    if (d->front->next == NULL)
        return DeleteFront(d);

    cell *temp = d->front;
    while (temp->next != d->rear)
        temp = temp->next;
    temp->next = NULL;
    free(d->rear);
    d->rear = temp;

    return 1;
}

// Returns front of a deque
int FrontD(deque q, DS_element *e)
{
    if (isEmptyDeque(q))
        return 0;

    *e = q.front->data;
    return 1;
}

// Returns rear of a deque
int Rear(deque q, DS_element *e)
{
    if (isEmptyDeque(q))
        return 0;

    *e = q.rear->data;
    return 1;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// ADDITIONAL

int DeleteDeque(deque *d)
{
    if (isEmptyDeque(*d))
        return 0;
    while (DeleteFront(d))
        ;
    return 1;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif