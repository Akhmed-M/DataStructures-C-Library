#include "./Tools/DataStructures/Stack.c"

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

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
            printf("%d ", e->data);
            if (e->left)
                Push(&odds, e->left);
            if (e->right)
                Push(&odds, e->right);
            // Push left then right => right is printed first (next loop)
        }
        while (Top(odds, &e))
        {
            Pop(&odds);
            printf("%d ", e->data);
            if (e->right)
                Push(&evens, e->right);
            if (e->left)
                Push(&evens, e->left);
            // Push right then left => left is printed first (next loop)
        }
    }
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// TEST

BTree test_tree()
{
    /*
                5
              /   \
             7     35
            /     /  \
          11     8    15
         /        \
        0          9
    */

    BTree root = createNode(5);

    root->left = createNode(7);
    root->right = createNode(35);

    root->left->left = createNode(11);
    root->left->left->left = createNode(0);

    root->right->right = createNode(15);
    root->right->left = createNode(8);
    root->right->left->right = createNode(9);

    return root;
}

void main()
{
    BTree root = test_tree();

    Print_ZigZagOrder(root); // Expected output = 5 35 7 11 8 15 9 0
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
