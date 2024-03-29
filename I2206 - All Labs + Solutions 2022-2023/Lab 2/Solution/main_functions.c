#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int element;
typedef struct node
{
    element data;
    struct node *next;
} node;

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

void InsertHead(node **headPtr, element data)
{
    if (headPtr == NULL)
        return;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;

    newNode->next = *headPtr;
    *headPtr = newNode;
}

void DeleteHead(node **headPtr)
{
    if (headPtr == NULL || (*headPtr) == NULL)
        return;
    node *head = *headPtr;
    (*headPtr) = (*headPtr)->next;
    head->next = NULL;
    free(head);
}

int PrintList(node *head) // USED FOR TESTING
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }
    int count = 0;
    printf("List = ");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
        count++;
    }
    printf("\n");
    return count;
}

node *reverse(node *head)
{
    if (!head || !(head->next))
        return head;

    node *newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/