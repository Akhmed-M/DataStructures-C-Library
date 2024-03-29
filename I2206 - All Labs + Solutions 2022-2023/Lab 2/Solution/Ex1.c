#include "main_functions.c"

node *getIntersection(node *headA, node *headB)
{
    node *tempA, *tempB;
    tempA = headA;
    tempB = headB;

    while (tempA != tempB)
    {
        if (tempA == NULL)
            tempA = headB;
        if (tempB == NULL)
            tempB = headA;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return tempA;
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
    InsertHead(&headA, 1);
    InsertHead(&headA, 2);
    InsertHead(&headA, 4);
    InsertHead(&headA, 6);

    InsertHead(&headB, 7);
    InsertHead(&headB, 4);
    InsertHead(&headB, 5);
    InsertHead(&headB, 6);

    /*---------------------------------*/
    /*---------------------------------*/

    // CREATE INTERSECTION
    node *temp = headB;
    while (temp->next)
        temp = temp->next;
    temp->next = headA->next->next; // POINTS TO THIRD NODE IN HEADA LIST

    PrintList(headA);
    PrintList(headB);

    // GET INTERSECTION
    node *intersection = getIntersection(headA, headB);
    printf("\nIntersection = %d\n", intersection->data);
}

void main()
{
    Test();
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/