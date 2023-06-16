#ifndef COUNT_TREENODES_C
#define COUNT_TREENODES_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// IMPORTS

#include "./DataStructures/Tree_Type.h"
#include "./DataStructures/Queue.c" // used by `width` function
#include "./BTree_basicTools.c"     // contains `isLeafNode` function (used below)

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PROTO-TYPES

int sizeOf_tree(BTree root);
int nbOf_leafNodes(BTree root);
int nbOf_nonLeafNodes(BTree root);
int height(BTree root);
int width(BTree root);
int delta_heights(BTree root);

int is_balanced(BTree root); // uses height & delta_heights functions

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Returns number of nodes in the tree
int sizeOf_tree(BTree root)
{
    if (root == NULL)
        return 0;
    return 1 + sizeOf_tree(root->left) + sizeOf_tree(root->right);
}

// Returns number of leaf-nodes in a tree
int nbOf_leafNodes(BTree root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return nbOf_leafNodes(root->left) + nbOf_leafNodes(root->right);
}

// Returns number of non-leaf-nodes in a tree
int nbOf_nonLeafNodes(BTree root)
{
    if (!root || isLeafNode(root))
        return 0;
    return 1 + nbOf_nonLeafNodes(root->left) + nbOf_nonLeafNodes(root->right);
}

// Returns vertical height of a tree
int height(BTree root)
{
    if (root == NULL)
        return 0;
    return 1 + max_of2Ints(height(root->left), height(root->right));
}

// Returns difference in heights between left & right (left-right)
int delta_heights(BTree root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

// Checks whether a tree is balanced or not
int is_balanced(BTree root)
{
    if (root == NULL)
        return 1; // empty = balanced
    if (abs(delta_heights(root)) > 1)
        return 0;                                               // not balanced
    return is_balanced(root->left) && is_balanced(root->right); // check sub-trees
}

// Returns max number of nodes, existing in a single level
int width(BTree root)
{
    if (root == NULL)
        return 0;
    if (isLeafNode(root))
        return 1;
    queue q = CreateQueue();
    EnQueue(&q, root);

    int width, n;
    width = n = 0;
    // n = number of nodes in current level
    // width = max number of nodes existing in a single level

    BTree e, first, next;
    first = root;

    while (Front(q, &e))
    {
        DeQueue(&q);
        if (e->left)
        {
            EnQueue(&q, e->left);
            n++;
        }
        if (e->right)
        {
            EnQueue(&q, e->right);
            n++;
        }
        // CHECK IF CURRENT LEVEL IS DONE
        if (Front(q, &next) && (next == first->right || next == first->left))
        {
            // UPDATE width
            if (n > width)
                width = n;
            // RESET
            n = 0;
            first = next;
        }
    }
    return width;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif