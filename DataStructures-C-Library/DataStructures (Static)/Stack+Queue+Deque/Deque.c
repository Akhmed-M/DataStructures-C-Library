#ifndef DEQUE_C
#define DEQUE_C

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// IMPORTS/DEFINITIONS

#include "Type.h"
typedef struct
{
    DS_element *data;
    int front, rear, size;
} deque;

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// PROTO-TYPES

deque CreateDeque(int N);
int isFullDeque(deque q);
int isEmptyDeque(deque q);
int Front(deque q, DS_element *e);
int Rear(deque q, DS_element *e);
int InsertFront(deque *q, DS_element data);
int InsertRear(deque *q, DS_element data);
int DeleteFront(deque *q);
int DeleteRear(deque *q);

void MoveDequeContent(deque *q1, deque *q2);

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// FUNCTIONS

deque CreateDeque(int N)
{
    deque q;
    q.front = 0;
    q.rear = -1;

    q.size = N + 1; // +1 FOR THE DUMMY NODE
    q.data = (DS_element *)malloc(sizeof(DS_element) * q.size);
    return q;
}

int isFullDeque(deque q)
{
    return (q.rear + 2) % q.size == q.front; // +2 BECAUSE OF THE DUMMY DS_element
}

int isEmptyDeque(deque q)
{
    return (q.rear + 1) % q.size == q.front;
}

int Front(deque q, DS_element *e)
{
    if (isEmptyDeque(q))
        return 0;
    *e = q.data[q.front];
    return 1;
}

int Rear(deque q, DS_element *e)
{
    if (isEmptyDeque(q))
        return 0;
    *e = q.data[q.rear];
    return 1;
}

int InsertFront(deque *q, DS_element data)
{
    if (isFullDeque(*q))
        return 0;

    q->front = (q->front - 1 + q->size) % q->size;
    q->data[q->front] = data;

    return 1;
}

int InsertRear(deque *q, DS_element data)
{
    if (isFullDeque(*q))
        return 0;
    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = data;
    return 1;
}

int DeleteFront(deque *q)
{
    if (isEmptyDeque(*q))
        return 0; // NOTHING TO DELETE
    q->front = (q->front + 1) % q->size;
    return 1;
}

int DeleteRear(deque *q)
{
    if (isEmptyDeque(*q))
        return 0; // NOTHING TO DELETE
    q->rear = (q->rear - 1 + q->size) % q->size;
    return 1;
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// TOOLS

// MOVES DEQUE CONTENT OF Q1 INTO Q2
void MoveDequeContent(deque *q1, deque *q2)
{
    if (isEmptyDeque(*q1))
        return 0; // FAILURE
    DS_element e;
    while (Front(*q1, &e) && InsertFront(q2, e))
        DeleteFront(q1);
    return 1; // SUCCESS
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

#endif