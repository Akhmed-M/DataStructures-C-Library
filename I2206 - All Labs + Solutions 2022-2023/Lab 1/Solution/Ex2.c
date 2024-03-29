#include "main_functions.c"

node *reverseList(node *head)
{
    node *prev = NULL; // previous
    node *cur = head;  // current
    node *next;        // next

    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
} // ITERATIVE

node *reverseList2(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
} // RECURSIVE

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TESTING

void Test()
{
    node *head = NULL;

    /*---------------------------------*/
    /*---------------------------------*/

    // BUILDING LIST = 1 2 3 4 5
    InsertHead(&head, 5);
    InsertHead(&head, 4);
    InsertHead(&head, 3);
    InsertHead(&head, 2);
    InsertHead(&head, 1);

    /*---------------------------------*/
    /*---------------------------------*/

    PrintList(head); // List = 1 2 3 4 5
    head = reverseList(head);
    // head = reverseList2(head);
    PrintList(head); // List = 5 4 3 2 1
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/