#ifndef STACK_C
#define STACK_C

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// IMPORTS/DEFINITIONS

#include "Type.h"
typedef struct
{
    DS_element *data;
    int top, size;
} stack;

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// PROTO-TYPES

stack CreateStack(int N);
int isEmptyStack(stack s);
int isFullStack(stack s);
int Top(stack s, DS_element *e);
int Push(stack *s, DS_element e);
int Pop(stack *s);

int MoveStackContent(stack *s1, stack *s2);
int sizeOfStack(stack s);

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// FUNCTIONS

stack CreateStack(int N)
{
    stack s;
    s.top = -1;
    s.size = N;
    s.data = (DS_element *)malloc(sizeof(DS_element) * N);
    return s;
}

int isEmptyStack(stack s)
{
    return (s.top == -1);
}

int isFullStack(stack s)
{
    return (s.top == s.size - 1);
}

int Top(stack s, DS_element *e)
{
    if (isEmptyStack(s))
        return 0; // FAIL
    *e = s.data[s.top];
    return 1; // SUCCESS
}

int Push(stack *s, DS_element e)
{
    if (isFullStack(*s))
        return 0; // FAIL

    s->data[++s->top] = e;
    return 1; // SUCCESS
}

int Pop(stack *s)
{
    if (isEmptyStack(*s))
        return 0; // FAIL
    s->top--;
    return 1; // SUCCESS
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/
// TOOLS

// MOVES CONTENT FROM S1 TO S2
int MoveStackContent(stack *s1, stack *s2)
{
    if (isEmptyStack(*s1))
        return 0;
    DS_element e;
    while (Top(*s1, &e) && Push(s2, e))
        Pop(s1);
    return 1;
}

int sizeOfStack(stack s)
{
    if (isEmptyStack(s))
        return 0;
    Pop(&s);
    return 1 + sizeOfStack(s);
}

/*------------------------------------------------------------------------*/
/*------------------------------------------------------------------------*/

#endif