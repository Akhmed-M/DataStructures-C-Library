#include "main_functions.c"

void removeDuplicates(node **headRef)
{
    // IF:  WRONG INPUT |OR| EMPTY |OR| ONE NODE EXISTS
    if (!headRef || !(*headRef) || !(*headRef)->next)
        return;

    node *head, *prev, *runner;
    head = *headRef;
    prev = NULL;

    /*  ALGORITHM:

        FOR CURRENT_NODE IN LIST
            FOR NODE=CURRENT_NODE IN LIST
                IF NODE->next = CURRENT_NODE
                    DELETE NODE->NEXT
                CONTINUE LOOPING
    */

    while (head && head->next)
    {
        runner = head;
        while (runner->next)
            if (runner->next->data == head->data)
                DeleteHead(&(runner->next)); // Delete node
            else
                runner = runner->next;
        head = head->next;
    }
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TESTING

void Test()
{
    node *head = NULL;

    /*---------------------------------*/
    /*---------------------------------*/

    // BUILDING LIST = 2 2 4 6 8 6 8 1 2
    InsertHead(&head, 2);
    InsertHead(&head, 1);
    InsertHead(&head, 8);
    InsertHead(&head, 6);
    InsertHead(&head, 8);
    InsertHead(&head, 6);
    InsertHead(&head, 4);
    InsertHead(&head, 2);
    InsertHead(&head, 2);

    /*---------------------------------*/
    /*---------------------------------*/

    PrintList(head); // BEFORE
    removeDuplicates(&head);
    PrintList(head); // AFTER
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/