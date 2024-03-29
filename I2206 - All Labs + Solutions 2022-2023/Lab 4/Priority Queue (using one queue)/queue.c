// Regular implementation of a queue
// only Element data-type changed

#include <stdio.h>
#include <stdlib.h>
/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// This is the part that changed

// Structure to represent an element in the priority queue
typedef struct
{
    char data;    // Element data
    int priority; // Priority value
} Element;

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

// Structure to represent the priority queue
typedef struct
{
    Element *queue; // Array to store elements and priorities
    int front;
    int capacity; // Maximum capacity of the queue
    int size;     // Current size of the queue
} PriorityQueue, Queue;

// Function to create a new priority queue
Queue createQueue(int capacity)
{
    Queue pq;
    pq.queue = (Element *)malloc(capacity * sizeof(Element));
    pq.capacity = capacity;
    pq.size = 0;
    pq.front = -1;
    return pq;
}

int is_empty(Queue *q)
{
    return q->size == 0;
}

int is_full(Queue *q)
{
    return q->size == q->capacity;
}

int front(Queue *q, Element *e)
{
    if (is_empty(q))
        return 0;
    *e = q->queue[q->front];
    return 1;
}

// Function to enqueue an element just like a regular queue
int enqueue(Queue *q, Element newElement)
{
    if (is_full(q))
        return 0; // No more space to enqueue
    q->queue[(q->front + q->size++) % q->capacity] = newElement;
    return 1;
}

// Function to dequeue an element just like a regular queue
int dequeue(Queue *q)
{
    if (is_empty(q))
        return 0;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return 1;
}

int move_queue_content(Queue *q1, Queue *q2)
{
    if (is_empty(q1) || q1 == q2)
        return 0;
    Element e;
    while (front(q1, &e) && enqueue(q2, e))
        dequeue(q1);
    return 1;
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
