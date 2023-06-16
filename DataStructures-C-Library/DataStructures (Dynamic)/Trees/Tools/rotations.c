#ifndef ROTATIONS_C
#define ROTATIONS_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#include "./DataStructures/Tree_Type.h"
#include "./count_treeNodes.c"
#include "./print_tree.c"

typedef BTree BST; // binary search tree is-a binary tree

// PROTO-TYPES

BST right_rotation(BST root);
BST left_rotation(BST root);
BST left_right_rotation(BST root);
BST right_left_rotation(BST root);

BST balance_once(BST root);
BST insert_balanced(BST root, int value);
BST balance(BST root);

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Function to perform right rotation
BST right_rotation(BST root)
{
    if (!root || !(root->left))
        return root;
    BST newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

// Function to perform right rotation
BST left_rotation(BST root)
{
    if (!root || !(root->right))
        return root;
    BST newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

// Function to perform a left rotation on the left node, then right rotation on root
BST left_right_rotation(BST root)
{
    if (!root || !(root->left) || !(root->left->right))
        return root;
    root->left = left_rotation(root->left);
    return right_rotation(root);
}

// Function to perform a right rotation on the right node, then left rotation on root
BST right_left_rotation(BST root)
{
    if (!root || !(root->right) || !(root->right->left))
        return root;
    root->right = right_rotation(root->right);
    return left_rotation(root);
}

// Perform convenient rotations in unbalance direction
BST balance_once(BST root)
{
    int delta = delta_heights(root);
    if (abs(delta) <= 1)
        return root; // already balanced
    // NOW WE ARE SURE THERE EXISTS AN UNBALANCE

    // Left Case
    if (delta > 1)
    {
        // Left Left Case
        if (delta_heights(root->left) >= 1)
            return right_rotation(root);
        // Left Right Case
        return left_right_rotation(root);
    }
    else // Right Case
    {
        // Right Right Case
        if (delta_heights(root->right) <= -1)
            return left_rotation(root);
        // Right Left Case
        return right_left_rotation(root);
    }
}

// Inserts a new node & restores balance if lost
BST insert_balanced(BST root, int value)
{
    if (!root)
        return createNode(value);
    if (compareTreeElements(root->data, value) == 0)
        return root; // already exists
    if (compareTreeElements(value, root->data) < 0)
        root->left = insert_balanced(root->left, value); // go left
    else
        root->right = insert_balanced(root->right, value); // go right
    return balance_once(root);
}

// Balances any binary tree
BST balance(BST root)
{
    if (!root)
        return root;
    root->left = balance(root->left);
    root->right = balance(root->right);
    return balance_once(root);
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif