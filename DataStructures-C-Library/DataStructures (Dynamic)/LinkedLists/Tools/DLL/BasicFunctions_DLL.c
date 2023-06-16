#ifndef BASICFUNCTION_DLL_C
#define BASICFUNCTION_DLL_C

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
#include "./Type_DLL.h"

// PROTO-TYPES

int size_DLL(DLL_Node *head);
int PrintList_DLL(DLL_Node *head);
int PrintListT_DLL(DLL_Node *head);

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/

// Returns length of a doubly linked list
int size_DLL(DLL_Node *head)
{
    if (!head)
        return 0;
    return 1 + size_DLL(head->next);
}

// Prints list & returns its length
int PrintList_DLL(DLL_Node *head)
{
    if (head == NULL)
    {
        printf("List is either empty OR printed!\n");
        return 0;
    }
    print_listElement(head->data);
    return 1 + PrintList_DLL(head->next);
}

// Prints list & returns its length
// USED FOR TESTING
int PrintListT_DLL(DLL_Node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return 0;
    }
    int flag = 0, count = 0;
    printf("Looping Forwards: ");
    while (head)
    {
        print_listElement(head->data);
        if (head->next == NULL || flag)
        {
            if (flag == 0)
            {
                printf("\nLooping Backwards: ");
                print_listElement(head->data);
                flag = 1;
                count++;
            }
            head = head->prev;
            continue;
        }
        head = head->next;
        count++;
    }
    printf("\n\n");
    return count;
}

/*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*/
#endif