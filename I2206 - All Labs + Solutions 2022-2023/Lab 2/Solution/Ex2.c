#include "main_functions.c"

void partitionLinkedList(node **headRef, int pivot)
{
    if (!headRef || !(*headRef) || !(*headRef)->next)
        return;

    node *temp = *headRef;

    node *left, *right, *left_tail, *right_tail;
    left = right = left_tail = right_tail = NULL;

    while (temp)
    {
        if (temp->data < pivot)
        {
            if (left == NULL)
                left = temp;
            else
                left_tail->next = temp;
            left_tail = temp;
        }
        else
        {
            if (right == NULL)
                right = temp;
            else
                right_tail->next = temp;
            right_tail = temp;
        }
        temp = temp->next;
    }

    // right_tail->next MAY BE A LEFT NODE
    if (right_tail)
        right_tail->next = NULL;

    if (left == NULL)
        *headRef = right; // NO LEFTS FOUND
    else
    {
        left_tail->next = right; // IF NO RIGHTS FOUND => RIGHT=NULL NO PROBLEM
        *headRef = left;
    }
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TEST

void Test()
{
    // CREATING LINKED LIST
    node *head = NULL;

    // BUILD LIST (List = 1 4 3 2 5 2)
    InsertHead(&head, 2);
    InsertHead(&head, 5);
    InsertHead(&head, 2);
    InsertHead(&head, 3);
    InsertHead(&head, 4);
    InsertHead(&head, 1);

    /*---------------------------------*/
    /*---------------------------------*/

    int pivot = 3;

    /*---------------------------------*/
    /*---------------------------------*/

    PrintList(head); // List = 1 4 3 2 5 2
    partitionLinkedList(&head, pivot);
    PrintList(head); // List = 1 2 2 4 3 5
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/