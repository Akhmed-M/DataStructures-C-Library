#ifndef QUEUE_C
#define QUEUE_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
#include "Type.h"

typedef struct
{
    cell *front, *rear;
} queue;

/*--------------------------------------------------*/
/*--------------------------------------------------*/
// PUBLIC FUNCTIONS

queue CreateQueue()
{
    queue q;
    q.front = q.rear = NULL;
    return q;
}

int isEmptyQueue(queue q)
{
    return q.front == NULL;
}

int Front(queue q, element *e)
{
    if (isEmptyQueue(q))
        return 0;

    *e = (q.front)->data;
    return 1;
}

// INSERT TAIL
int EnQueue(queue *q, element newElement)
{
    // ALLOCATE & FILL
    cell *newcell = (cell *)malloc(sizeof(cell));
    if (!newcell)
        return 0; // MEMORY ERROR
    newcell->data = newElement;
    newcell->next = NULL; // NEW REAR => NEXT=NULL

    // LINK
    if (isEmptyQueue(*q))
        q->front = newcell;
    else
        q->rear->next = newcell;
    q->rear = newcell;

    return 1;
}

// DELETE HEAD
int DeQueue(queue *q)
{
    if (isEmptyQueue(*q))
        return 0;

    // REMOVE FRONT
    cell *head = q->front;
    (q->front) = (q->front)->next;

    head->next = NULL;
    free(head);

    // IF WE REMOVED LAST NODE
    if (isEmptyQueue(*q))
        q->rear = NULL;

    return 1;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif