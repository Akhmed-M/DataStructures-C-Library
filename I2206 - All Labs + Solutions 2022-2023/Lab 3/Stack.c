#ifndef STACK_C
#define STACK_C

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
    element *data;
    int top, size;
} stack;

stack CreateStack(int N)
{
    stack s;
    s.top = -1;
    s.size = N;
    s.data = (element *)malloc(sizeof(element) * N);
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

int Top(stack s, element *e)
{
    if (isEmptyStack(s))
        return 0; // FAIL
    *e = s.data[s.top];
    return 1; // SUCCESS
}

int Push(stack *s, element e)
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

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// TOOLS

// APPROPRIATE FOR ELEMENT VALUES X (-10 < X < 10)
void DisplayStack(stack s)
{
    if (isEmptyStack(s))
    {
        printf("Stack is empty!\n");
        return;
    }

    printf("Displaying Stack:\n");
    element e;
    while (Top(s, &e) && Pop(&s))
    {
        printf("\t\t\t");
        if (e < 0)
            printf("| %d  |\n", e);
        else
            printf("|  %d  |\n", e);
    }
    printf("\t\t\t");
    printf("-------\n\n");
}

// MOVES CONTENT FROM S1 TO S2
int MoveStackContent(stack *s1, stack *s2)
{
    if (isEmptyStack(*s1))
        return 0;
    element e;
    while (Top(*s1, &e) && Push(s2, e))
        Pop(s1);
    return 1;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

#endif