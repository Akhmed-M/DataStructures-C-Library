#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
    element *data;
    int top1, top2, size;
} twoStacks;

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// MAIN FUNCTIONS

twoStacks CreateNewStack(int N)
{
    twoStacks s;
    s.top1 = -1;
    s.top2 = s.size = N;
    s.data = (element *)malloc(sizeof(element) * N);
    return s;
}

int isEmptyStack(twoStacks s, int n)
{
    if (n == 1)
        return s.top1 == -1;
    return s.top2 == s.size;
}

int isFullStack(twoStacks s)
{
    return (s.top1 + 1 == s.top2);
}

int Top(twoStacks s, element *e, int n)
{
    if (isEmptyStack(s, n))
        return 0;
    if (n == 1)
        *e = s.data[s.top1];
    else
        *e = s.data[s.top2];
    return 1;
}

int Push(twoStacks *s, element e, int n)
{
    if (isFullStack(*s))
        return 0;
    if (n == 1)
        s->data[++s->top1] = e;
    else
        s->data[--s->top2] = e;
    return 1;
}

int Pop(twoStacks *s, int n)
{
    if (isEmptyStack(*s, n))
        return 0;
    if (n == 1)
        s->top1--;
    else
        s->top2++;
    return 1;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
