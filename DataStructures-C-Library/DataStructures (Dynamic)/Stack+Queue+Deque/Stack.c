#ifndef STACK_C
#define STACK_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
#include "Type.h"

typedef cell *stack;

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PUBLIC FUNCTIONS

stack CreateStack()
{
    return NULL;
}

int isEmptyStack(stack s)
{
    return (s == NULL);
}

int isFullStack(stack s)
{
    return 0; // DYNAMIC STACK IS NEVER FULL => UNLESS NO MORE MEMORY AVAILABLE (MALLOC ERROR)
}

int Top(stack s, DS_element *e)
{
    if (isEmptyStack(s))
        return 0;
    *e = create_DS_element(s->data);
    return 1;
}

int Push(stack *s, DS_element e)
{
    cell *newCell = (cell *)malloc(sizeof(cell));
    if (newCell == NULL)
        return 0; // MEMORY ERROR

    newCell->data = create_DS_element(e);
    newCell->next = *s;
    *s = newCell;
    return 1; // SUCCESS
}

int Pop(stack *s)
{
    if (s == NULL || isEmptyStack(*s))
        return 0; // ALREADY EMPTY
    cell *top = *s;
    (*s) = (*s)->next;
    free(top);
    return 1; // SUCCESS
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// TOOLS

// DELETE THE LINKED LIST
int EmptyTheStack(stack *s)
{
    if (s == NULL || isEmptyStack(*s))
        return 0;
    while (Pop(s))
        ;
    return 1;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
#endif