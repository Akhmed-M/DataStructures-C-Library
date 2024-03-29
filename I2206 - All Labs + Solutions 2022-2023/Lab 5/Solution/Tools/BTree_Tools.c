#ifndef BTREE_TOOLS_C
#define BTREE_TOOLS_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// IMPORTS

#include "./DataStructures/Type.h"
#include <limits.h>

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PROTO-TYPES

int max_of2Ints(int a, int b);

int isLeafNode(BTree root);
int height(BTree root);
int delta_heights(BTree root);

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Returns max of 2 integers
int max_of2Ints(int a, int b)
{
    return (a > b) ? a : b;
}

int isLeafNode(BTree root)
{
    return (root->left == NULL && root->right == NULL);
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

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif
