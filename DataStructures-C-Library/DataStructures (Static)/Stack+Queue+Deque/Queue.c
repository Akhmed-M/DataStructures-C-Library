#ifndef QUEUE_C
#define QUEUE_C

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// IMPORTS/DEFINITIONS

#include "Type.h"
typedef struct
{
    DS_element *data;
    int front, length;
    int size; // CONSTANT - CHOSEN WHEN CREATING THE QUEUE
} queue;

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// PROTO-TYPES

queue CreateQueue(int size);
int isEmptyQueue(queue q);
int isFullQueue(queue q);
int Front(queue q, DS_element *e);
int EnQueue(queue *q, DS_element newDS_element);
int DeQueue(queue *q);

int MoveQueueContent(queue *q1, queue *q2);

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// IMPLEMENTATION

queue CreateQueue(int size)
{
    queue q;
    q.front = q.length = 0;

    q.size = size;
    q.data = (DS_element *)malloc(sizeof(DS_element) * size);
    return q;
}

int isEmptyQueue(queue q)
{
    return q.length == 0;
}

int isFullQueue(queue q)
{
    return q.length == q.size;
}

int Front(queue q, DS_element *e)
{
    if (isEmptyQueue(q))
        return 0;
    *e = q.data[q.front];
    return 1;
}

int EnQueue(queue *q, DS_element newDS_element)
{
    if (isFullQueue(*q))
        return 0;
    q->data[(q->front + q->length++) % q->size] = newDS_element;
    return 1;
}

int DeQueue(queue *q)
{
    if (isEmptyQueue(*q))
        return 0;
    q->front = (q->front + 1) % q->size;
    q->length--;
    return 1;
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// TOOLS

// MOVES QUEUE CONTENT OF Q1 INTO Q2
int MoveQueueContent(queue *q1, queue *q2)
{
    if (isEmptyQueue(*q1))
        return 0; // FAILURE
    DS_element e;
    while (Front(*q1, &e) && EnQueue(q2, e))
        DeQueue(q1);
    return 1; // SUCCESS
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

#endif