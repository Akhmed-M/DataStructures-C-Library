#include "main_functions.c"

node *mergeTwoLists(node *l1, node *l2)
{
    // l1 AND l1 ARE ASSUMED TO BE SORTED
    node dummy;
    node *tail = &dummy;

    while (1)
    {
        if (l1 == NULL)
        {
            tail->next = l2;
            break;
        }
        if (l2 == NULL)
        {
            tail->next = l1;
            break;
        }
        // IF BOTH ARE NOT NULL
        if (l1->data < l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    return dummy.next;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TESTING

void Test()
{
    node *headA, *headB;
    headA = headB = NULL;

    /*---------------------------------*/
    /*---------------------------------*/

    // BUILDING LIST = 2 4 6 8
    InsertHead(&headA, 8);
    InsertHead(&headA, 6);
    InsertHead(&headA, 4);
    InsertHead(&headA, 2);

    // BUILDING LIST = 1 3 4 5 7 9
    InsertHead(&headB, 9);
    InsertHead(&headB, 7);
    InsertHead(&headB, 5);
    InsertHead(&headB, 4);
    InsertHead(&headB, 3);
    InsertHead(&headB, 1);

    /*---------------------------------*/
    /*---------------------------------*/

    PrintList(headA); // List = 2 4 6 8
    PrintList(headB); // List = 1 3 4 5 7 9

    node *merged = mergeTwoLists(headA, headB);
    PrintList(merged); // List = 1 2 3 4 4 5 6 7 8 9
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/