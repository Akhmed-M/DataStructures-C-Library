#include "queue.c"

// This file takes a regular queue
// and adds the functionality of enqueing elements according to priority

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

// insert sorted according to priority
int enqueue_pq(PriorityQueue *pq, Element newElement)
{
    if (is_full(pq))
        return 0;
    Queue temp = createQueue(pq->capacity);
    Element e;
    while (front(pq, &e) && newElement.priority <= e.priority)
    {
        dequeue(pq);
        enqueue(&temp, e);
    }
    enqueue(&temp, newElement);
    move_queue_content(pq, &temp);
    move_queue_content(&temp, pq);
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

    enqueue_pq(&pq, (Element){'a', 3});
    enqueue_pq(&pq, (Element){'b', 3});
    enqueue_pq(&pq, (Element){'c', 3});
    enqueue_pq(&pq, (Element){'d', 4});
    enqueue_pq(&pq, (Element){'e', 4});
    enqueue_pq(&pq, (Element){'f', 3});
    enqueue_pq(&pq, (Element){'h', 5});
    enqueue_pq(&pq, (Element){'i', 9});
    enqueue_pq(&pq, (Element){'j', 1});
    display_queue(pq); // Expected output = `i h d e a b c f j`

    // enqueue(&pq, (Element){'a', 3});
    // enqueue(&pq, (Element){'b', 3});
    // enqueue(&pq, (Element){'c', 3});
    // enqueue(&pq, (Element){'d', 4});
    // enqueue(&pq, (Element){'e', 4});
    // enqueue(&pq, (Element){'f', 3});
    // enqueue(&pq, (Element){'h', 5});
    // enqueue(&pq, (Element){'i', 9});
    // enqueue(&pq, (Element){'j', 1});
    // display_queue(pq); // Expected output = `a b c d e f g h i j`
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
