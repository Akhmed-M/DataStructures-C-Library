#include "main_functions.c"

node *rotateRight(node *head, int k)
{
    if (!head || !(head->next) || k <= 0)
        return head;

    // GET LENGTH & TAIL
    int length = 0;
    node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        length++;
    }

    // GET RID OF UNNECESSARY ROTATIONS
    k %= ++length;
    if (k == 0)
        return head;

    // ROTATE
    int pos = 0;
    node *cur = head;
    node *prev = NULL;

    while (cur)
    {
        if (pos++ == length - k)
        {
            prev->next = NULL;
            tail->next = head;
            return cur; // cur = FIRST NODE OF ROTATION PARTITION
        }
        prev = cur;
        cur = cur->next;
    }
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TEST

void Test()
{
    // CREATING LINKED LIST
    node *head = NULL;

    // BUILD LIST
    InsertHead(&head, 1);
    InsertHead(&head, 2);
    InsertHead(&head, 4);
    InsertHead(&head, 6);

    /*---------------------------------*/
    /*---------------------------------*/

    int k = 5; // NUMBER OF ROTATIONS

    /*---------------------------------*/
    /*---------------------------------*/

    PrintList(head); // BEFORE
    head = rotateRight(head, k);
    PrintList(head); // AFTER
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/