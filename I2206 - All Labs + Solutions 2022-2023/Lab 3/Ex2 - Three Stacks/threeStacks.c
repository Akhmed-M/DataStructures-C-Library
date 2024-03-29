#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct
{
    element *data;
    int top1, top2, top3;
    int bottom3, size;
} threeStacks;

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// PROTO-TYPES

// MAIN FUNCTIONS
threeStacks CreateNewStack(int N);
int isEmptyStack(threeStacks s, int n);
int isFullStack(threeStacks s);
int Push(threeStacks *s, element newElement, int n);

// SHIFTING STACK_3
void shiftLeft(threeStacks *s);
void shiftRight(threeStacks *s);

// TESTING
void displayStack(threeStacks s, int n);
void displayThreeStacks(threeStacks s);

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// MAIN FUNCTIONS

threeStacks CreateNewStack(int N)
{
    threeStacks s;
    s.top1 = -1;
    s.top2 = s.size = N;
    s.top3 = N / 2;

    s.data = (element *)malloc(sizeof(element) * N);
    s.bottom3 = s.top3 + 1;
    return s;
}

int isEmptyStack(threeStacks s, int n)
{
    if (n == 1)
        return s.top1 == -1;
    if (n == 2)
        return s.top2 == s.size;
    return s.top3 < s.bottom3;
}

int isFullStack(threeStacks s)
{
    return (s.top1 + 1 == s.bottom3) && (s.top3 + 1 == s.top2);
}

int Pop(threeStacks *s, int n)
{
    if (isEmptyStack(*s, n))
        return 0;

    if (n == 1)
        s->top1--;
    else if (n == 2)
        s->top2++;
    else
        s->top3--;
    return 1;
}

int Push(threeStacks *s, element newElement, int n)
{
    if (isFullStack(*s))
        return 0;

    if (n == 1)
    {
        if (s->top1 + 1 == s->bottom3)
            shiftRight(s);
        s->data[++s->top1] = newElement;
    }
    else
    {
        if (s->top3 + 1 == s->top2)
            shiftLeft(s);
        if (n == 2)
            s->data[--s->top2] = newElement;
        else
            s->data[++s->top3] = newElement;
    }
    return 1;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// HELPER FUNCTIONS - SHIFTING STACK_3

/*
    METHOD:
        MOVE STACK_3 TO THE MIDDLE OF THE ARRAY
        TO TRY LEAVE EMPTY SPACES ON BOTH SIDES LEFT AND RIGHT
        IN ORDER TO REDUCE NUMBER OF TIMES WE HAVE TO SHIFT THE STACK
        WHICH RESULTS IN LESS AVERAGE TIME COMPLEXITY
*/

// NOTE:
// if (s->bottom3 == s->top1 + 1) then 0 empty spaces left between stack_1 & stack_3
// else their difference = empty spaces left

// SHIFT ALL STACK_3 ELEMENTS TO THE LEFT
void shiftLeft(threeStacks *s)
{
    // GET NUMBER OF EMPTY SPACES BETWEEN STACK_1 & STACK_3
    int empty = s->bottom3 - (s->top1 + 1);

    // MOVE STACK_3 TO THE MIDDLE OF THE ARRAY
    for (int i = s->bottom3; i <= s->top3; i++)
        s->data[i - (empty / 2 + 1)] = s->data[i];

    // SHIFT ITS INDICES TO THE LEFT
    s->bottom3 -= empty / 2 + 1;
    s->top3 -= empty / 2 + 1;
}

// NOTE:
// if (s->top2 == s->top3 + 1): then 0 empty spaces left between stack_3 & stack_2
// else: their difference = number of empty spaces left

// SHIFT ALL STACK_3 ELEMENTS TO THE RIGHT
void shiftRight(threeStacks *s)
{
    // GET NUMBER OF EMPTY SPACES BETWEEN STACK_1 & STACK_3
    int empty = s->top2 - (s->top3 + 1);

    // MOVE STACK_3 TO THE MIDDLE OF THE ARRAY
    for (int i = s->top3; i >= s->bottom3; i--)
        s->data[i + empty / 2 + 1] = s->data[i];

    // SHIFT ITS INDICES TO THE RIGHT
    s->bottom3 += empty / 2 + 1;
    s->top3 += empty / 2 + 1;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

// NOTE:
// THESE SHIFT FUNCTIONS ARE WORSE THAN THE ONES USED ABOVE, IN TERMS OF AVERAGE TIME COMPLEXITY
// THIS IS WHY THEY ARE COMMENTED

/*
// SHIFTING STACK_3 ONE INDEX IN THE EMPTY SPACE DIRECTION

void shiftLeft(threeStacks *s)
{
    // SHIFT ALL STACK_3 ELEMENTS TO THE LEFT
    for (int i = s->bottom3; i <= s->top3; i++)
        s->data[i - 1] = s->data[i];

    // SHIFT ITS INDICES TO THE LEFT
    s->bottom3--;
    s->top3--;
}
void shiftRight(threeStacks *s)
{
    // SHIFT ALL STACK_3 ELEMENTS TO THE RIGHT
    for (int i = s->top3; i >= s->bottom3; i--)
        s->data[i + 1] = s->data[i];

    // SHIFT ITS INDICES TO THE RIGHT
    s->bottom3++;
    s->top3++;
}
*/

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
