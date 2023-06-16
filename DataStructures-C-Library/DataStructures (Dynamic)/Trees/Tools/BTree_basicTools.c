#ifndef BTREE_BASICTOOLS_C
#define BTREE_BASICTOOLS_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// IMPORTS

#include "./DataStructures/Tree_Type.h"

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PROTO-TYPES

int max_of2Ints(int a, int b);
int isLeafNode(BTree root);
BTree search_tree(BTree root, treeElement targetValue);

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Returns max of 2 integers
inline int max_of2Ints(int a, int b)
{
    return (a > b) ? a : b;
} // used to get height of a binary tree

// Checks if a node is a leaf-node
inline int isLeafNode(BTree root)
{
    return (root->left == NULL && root->right == NULL);
}

// Searches for a node in a binary tree (returns null if not found)
BTree search_tree(BTree root, treeElement targetValue)
{
    if (!root || compareTreeElements(root->data, targetValue) == 0)
        return root;
    BTree targetNode = search_tree(root->left, targetValue);
    if (!targetNode)
        return search_tree(root->right, targetValue);
    return targetNode;
}

// Returns the least common ancestor of two nodes in a binary tree
BTree least_common_ancestor(BTree root, BTree a, BTree b)
{
    if (!root || !a || !b)
        return NULL;
    if (root == a || root == b)
        return root;

    BTree left = least_common_ancestor(root->left, a, b);
    BTree right = least_common_ancestor(root->right, a, b);

    if (left && right)
        return root;
    if (left)
        return left;
    return right;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif
