#include "twoStacks.c"

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// PROTO-TYPES OF TEST-TOOLS

int DisplayTwoStacks(twoStacks s);
void DisplayStack(twoStacks s, int n);
void CleanStacks(twoStacks *s);

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

void main() // TEST
{
    twoStacks s = CreateNewStack(20);

    // STACK_1 = 3 7 1 8 0
    Push(&s, 3, 1);
    Push(&s, 7, 1);
    Push(&s, 1, 1);
    Push(&s, 8, 1);
    Push(&s, 0, 1);

    // STACK_2 = 8 1 4 2 9 5
    Push(&s, 8, 2);
    Push(&s, 1, 2);
    Push(&s, 4, 2);
    Push(&s, 2, 2);
    Push(&s, 9, 2);
    Push(&s, 5, 2);

    DisplayTwoStacks(s);

    printf("top1 = %d |&&| top2 = %d", s.top1, s.top2);
    // INDICES  = 0 1 2 3 4 ... 14 15 16 17 18 19
    // ELEMENTS = 3 7 1 8 0 ... 5  9  2  4  1  8
    //                    ^     ^
    //                    |     |
    //                   top1   |
    //                         top2

    // EMPTY THE STACKS
    CleanStacks(&s);
    DisplayTwoStacks(s); // WILL NOT PRINT ANYTHING
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// TEST-TOOLS

void DisplayStack(twoStacks s, int n)
{
    if (n == 1)
    {
        for (int i = 0; i <= s.top1; i++)
            printf("%d ", s.data[i]);
        return;
    }
    for (int i = s.top2; i < s.size; i++)
        printf("%d ", s.data[i]);
}

int DisplayTwoStacks(twoStacks s)
{
    if (isEmptyStack(s, 1) && isEmptyStack(s, 2))
        return 0;
    DisplayStack(s, 1);
    printf("| ");
    DisplayStack(s, 2);
    printf("\n");
    return 1;
}

void CleanStacks(twoStacks *s)
{
    s->top1 = -1;
    s->top2 = s->size;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
