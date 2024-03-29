#include "threeStacks.c"

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// PROTO-TYPES OF TEST-TOOLS

void displayStack(threeStacks s, int n);
void displayThreeStacks(threeStacks s);

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

void main() // TEST
{
    threeStacks s = CreateNewStack(10);

    // STACK_1: 7 8 9 10
    Push(&s, 7, 1);
    Push(&s, 8, 1);
    Push(&s, 9, 1);
    Push(&s, 10, 1);

    // STACK_2: 4 3 2 1 (STACK_2 IS IN REVERSE ORDER OF OTHER STACKS, IN THE ARRAY)
    Push(&s, 1, 2);
    Push(&s, 2, 2);
    Push(&s, 3, 2);
    Push(&s, 4, 2);

    // STACK_3: 5 6
    Push(&s, 5, 3);
    Push(&s, 6, 3);

    // THREESTACKS: 7 8 9 10 | 5 6 | 4 3 2 1
    displayThreeStacks(s);

    // THREESTACKS: 7 8 9 10 | 5 6 | 4 3 2 1
    //  s.top1    ==>     ^^   ^ ^   ^
    //  s.bottom3 ==>          | |   |
    //  s.top3    ==>            |   |
    //  s.top2    ==>                |

    printf("\n%d %d %d %d\n", s.top1, s.bottom3, s.top3, s.top2); // EXPECTED OUTPUT: 3 4 5 6
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
// TEST-TOOLS

// PRINT STACKS IN THE SAME ORDER THEY ARE IN THE ARRAY
void displayStack(threeStacks s, int n)
{
    if (isEmptyStack(s, n))
    {
        printf("Stack %d is empty!", n);
        return;
    }

    int low, high;
    if (n == 1)
    {
        low = 0;
        high = s.top1;
    }
    else if (n == 2)
    {
        low = s.top2;
        high = s.size - 1;
    }
    else if (n == 3)
    {
        low = s.bottom3;
        high = s.top3;
    }
    else
        return; // invalid stack number
    while (low <= high)
        printf("%d ", s.data[low++]);
}

void displayThreeStacks(threeStacks s)
{
    displayStack(s, 1);
    printf("| ");
    displayStack(s, 3);
    printf("| ");
    displayStack(s, 2);
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
