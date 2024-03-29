#include "main_functions.c"

node *addNumbers(node *num1, node *num2)
{
    if (num1 == NULL)
        return reverse(num2);
    if (num2 == NULL)
        return reverse(num1);

    node *result = NULL;
    int sum = 0;
    while (num1 || num2 || sum)
    {
        if (num1)
            sum += num1->data;
        if (num2)
            sum += num2->data;

        InsertHead(&result, sum % 10);
        sum = (sum > 9) ? 1 : 0;

        if (num1)
            num1 = num1->next;
        if (num2)
            num2 = num2->next;
    }
    return result;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TEST

void Test()
{
    // CREATING LINKED LISTS
    node *headA, *headB;
    headA = headB = NULL;

    // BUILD LISTS
    InsertHead(&headA, 3);
    InsertHead(&headA, 4);
    InsertHead(&headA, 2);

    InsertHead(&headB, 4);
    InsertHead(&headB, 6);
    InsertHead(&headB, 5);
    InsertHead(&headB, 8);

    /*---------------------------------*/
    /*---------------------------------*/

    PrintList(headA); // 2 4 3
    PrintList(headB); // 8 5 6 4

    node *sum = addNumbers(headA, headB); // 342 + 4658 = 5000
    PrintList(sum);                       // 5 0 0 0
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/