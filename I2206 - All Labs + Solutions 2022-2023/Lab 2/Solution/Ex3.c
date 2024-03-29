#include "main_functions.c"

bool hasCycle(node *head)
{
    if (!head)
        return false;

    node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

node *detectCycle(node *head)
{
    if (!head)
        return NULL;

    node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (slow != fast)
        return NULL; // NO CYCLE

    slow = head;
    fast = fast->next;

    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
// TEST

void Test()
{
    // CREATING LINKED LIST
    node *head = NULL;

    // BUILD LIST: 10 6 8 -4 0 2 3
    InsertHead(&head, 3);
    InsertHead(&head, 2);
    InsertHead(&head, 0);
    InsertHead(&head, -4);
    InsertHead(&head, 8);
    InsertHead(&head, 6);
    InsertHead(&head, 10);

    PrintList(head);

    /*---------------------------------*/
    /*---------------------------------*/

    // CREATE CYCLE
    node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = head->next->next; // CONNECT TAIL TO 3RD NODE

    printf("\nCycle head = ?\n");
    printf("Expected = %d\n", temp->next->data);

    /*---------------------------------*/
    /*---------------------------------*/

    node *cycleHead = detectCycle(head);
    printf("Result   = %d\n", cycleHead->data);
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

// SAME ALGORITHM OF `detectCycle` BUT DIFFERENT CODE (ONLY ONE WHILE LOOP)
node *detectCycle2(node *head)
{
    if (!head)
        return NULL;

    // DECLARE
    node *slow, *fast, *cycleHead;
    slow = head;
    fast = head->next;
    int cycleFound = 0;

    while (fast && fast->next)
    {
        if (cycleFound)
        {
            if (slow == fast)
                return slow;
            slow = slow->next;
            fast = fast->next;
            continue;
        }
        if (slow == fast)
        {
            cycleFound = 1;
            slow = head;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return NULL;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/