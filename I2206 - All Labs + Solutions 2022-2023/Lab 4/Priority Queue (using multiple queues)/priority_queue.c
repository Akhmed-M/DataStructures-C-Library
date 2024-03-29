#include "queue.c"

// This file takes a regular queue
// and adds the functionality of enqueing elements according to priority

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

#define N 10                 // priorities
typedef Queue PriorityQueue; // a priority queue is a queue

// takes a queue and turns it into a priority queue
int sort(Queue *q)
{
    if (is_empty(q))
        return 0; // empty = sorted

    // initialize multiple queues (number of possible priorities)
    Queue temps[N];
    for (int i = 0; i < N; i++)
        temps[i] = createQueue(q->size);

    // arrange elements into multiple queues according to their priorities
    Element e;
    while (front(q, &e))
    {
        enqueue(&temps[e.priority], e);
        dequeue(q);
    }

    // restore elements in arranged order (highest to lowest priority)
    for (int i = N - 1; i >= 0; i--)
        while (front(&temps[i], &e))
        {
            dequeue(&temps[i]);
            enqueue(q, e);
        }
    return 1;
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// Test

void display_queue(Queue q)
{
    if (is_empty(&q))
        return;
    Element e;
    while (front(&q, &e) && dequeue(&q))
        printf("%c ", e);
    printf("\n");
}

void main()
{
    Queue pq = createQueue(10);

    enqueue(&pq, (Element){'a', 3});
    enqueue(&pq, (Element){'b', 3});
    enqueue(&pq, (Element){'c', 3});
    enqueue(&pq, (Element){'d', 4});
    enqueue(&pq, (Element){'e', 4});
    enqueue(&pq, (Element){'f', 3});
    enqueue(&pq, (Element){'h', 5});
    enqueue(&pq, (Element){'i', 9});
    enqueue(&pq, (Element){'j', 1});

    display_queue(pq); // Expected output = `a b c d e f h i j`
    sort(&pq);
    display_queue(pq); // Expected output = `i h d e a b c f j`
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
