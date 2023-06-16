#ifndef PRINT_TREE_C
#define PRINT_TREE_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// IMPORTS

#include "./DataStructures/Tree_Type.h"
#include "./DataStructures/Stack.c"
#include "./DataStructures/Queue.c"

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PROTO-TYPES

void Print_InOrder(BTree root);          // recursive
void Print_PreOrder(BTree root);         // recursive
void Print_PostOrder(BTree root);        // recursive
void Print_LevelOrder(BTree root);       // uses a queue
void Print_InOrder_I(BTree root);        // uses a stack
void Print_InOrder_Reversed(BTree root); // uses a stack
void Print_ZigZagOrder(BTree root);      // uses a stack

BTree getNextLeft(BTree root, stack *s);
BTree getPrevRight(BTree root, stack *s);

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PRINT FUNCTIONS

void Print_InOrder(BTree root)
{
    if (root == NULL)
        return;
    Print_InOrder(root->left);
    printTreeElement(root->data);
    Print_InOrder(root->right);
}

void Print_PreOrder(BTree root)
{
    if (root == NULL)
        return;
    printTreeElement(root->data);
    Print_PreOrder(root->left);
    Print_PreOrder(root->right);
}

void Print_PostOrder(BTree root)
{
    if (root == NULL)
        return;
    Print_PostOrder(root->left);
    Print_PostOrder(root->right);
    printTreeElement(root->data);
}

void Print_LevelOrder(BTree root)
{
    if (root == NULL)
        return;
    BTree e;
    queue q = CreateQueue();
    EnQueue(&q, root);
    while (Front(q, &e))
    {
        DeQueue(&q);
        printTreeElement(e->data);
        if (e->left)
            EnQueue(&q, e->left);
        if (e->right)
            EnQueue(&q, e->right);
    }
    printf("\n");
}

void Print_ZigZagOrder(BTree root)
{
    if (root == NULL)
        return;
    stack evens = CreateStack(); // for even levels
    stack odds = CreateStack();  // for odd levels
    Push(&evens, root);

    BTree e;
    while (!isEmptyStack(evens))
    {
        while (Top(evens, &e))
        {
            Pop(&evens);
            printTreeElement(e->data);
            if (e->left)
                Push(&odds, e->left);
            if (e->right)
                Push(&odds, e->right);
            // Push left then right => right is printed first (next loop)
        }
        while (Top(odds, &e))
        {
            Pop(&odds);
            printTreeElement(e->data);
            if (e->right)
                Push(&evens, e->right);
            if (e->left)
                Push(&evens, e->left);
            // Push right then left => left is printed first (next loop)
        }
    }
}

// Print In-Order (Iterative Version)
void Print_InOrder_I(BTree root)
{
    if (!root)
        return;
    stack s = CreateStack();
    root = getNextLeft(root, &s);

    while (root)
    {
        printTreeElement(root->data);
        root = getNextLeft(root->right, &s);
    }
    printf("\n");
}

void Print_InOrder_Reversed(BTree root)
{
    if (!root)
        return;
    stack s = CreateStack();
    root = getPrevRight(root, &s);
    while (root)
    {
        printTreeElement(root->data);
        root = getPrevRight(root->left, &s);
    }
    printf("\n");
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// HELPER FUNCTIONS

// Pushes to the stack all nodes on the path to the minimum, then returns the minimum
BTree getNextLeft(BTree root, stack *s)
{
    if (root == NULL)
    {
        // pop and return top
        if (!Top(*s, &root)) // get min
            return NULL;     // stack is empty
        Pop(s);
        return root;
    }
    Push(s, root);
    return getNextLeft(root->left, s); // go left
}

// Pushes to the stack all nodes on the path to the maximum, then returns the maximum
BTree getPrevRight(BTree root, stack *s)
{
    if (root == NULL)
    {
        // pop and return top
        if (!Top(*s, &root)) // get max
            return NULL;     // stack is empty
        Pop(s);
        return root;
    }
    Push(s, root);
    return getPrevRight(root->right, s); // go right
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif