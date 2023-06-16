#ifndef TREE_DELETION
#define TREE_DELETION

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#include "./DataStructures/Tree_Type.h"
typedef BTree BST; // binary search tree is-a binary tree

int delete_node(BTree *parentPointer);
int delete_targetNode(BTree *root, treeElement targetValue);
int delete_targetNode_BST(BST *root, treeElement targetValue);

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

int delete_targetNode(BTree *root, treeElement targetValue)
{
    if (!root || !(*root))
        return 0; // wrong input or empty tree (nothing to delete)
    if (compareTreeElements((*root)->data, targetValue) == 0)
        return delete_node(root); // found
    // traverse tree to find target node
    return delete_targetNode(&((*root)->left), targetValue) || delete_targetNode(&((*root)->right), targetValue);
}

// Deletes a node in a BST
int delete_targetNode_BST(BST *root, treeElement targetValue)
{
    if (!root || !(*root))
        return 0; // wrong input or empty tree (nothing to delete)
    if (compareTreeElements(targetValue, (*root)->data) == 0)
        return delete_node(root); // found
    // traverse tree to find target node
    if (compareTreeElements(targetValue, (*root)->data) < 0)
        return delete_targetNode_BST(&((*root)->left), targetValue); // go left
    return delete_targetNode_BST(&((*root)->right), targetValue);    // go right
}

// Deletes a node pointed by its parent-node (or a static variable)
// parentPointer = &root or &(parent->right) or &(parent->left)
int delete_node(BTree *parentPointer)
{
    /* METHOD:
        * find min node of right sub-tree
            (node that is directly greater than targetNode we're pointing at)
        * swap value of targetNode with that of min node
        * delete the original min node (inside the right sub-tree)
    */
    if (!parentPointer || !(*parentPointer))
        return 0; // wrong input or empty tree (nothing to delete)

    BTree temp;
    // check if node has 2 children
    if ((*parentPointer)->left && (*parentPointer)->right)
    {
        // get min node of right-subtree
        BTree prev = NULL;
        temp = (*parentPointer)->right;
        while (temp->left)
        {
            prev = temp;
            temp = temp->left;
        } // now temp = min-node of right-subtree

        // place min-value inside targetNode
        (*parentPointer)->data = temp->data;

        // skip min node (temp)
        if (prev == NULL)
            (*parentPointer)->right = temp->right;
        else
            prev->left = temp->right; // note that temp->left = null
    }
    else // targetNode is leaf node or has one child
    {
        // skip targetNode
        temp = *parentPointer; // temp = targetNode
        if (temp->left)
            *parentPointer = temp->left;
        else
            *parentPointer = temp->right;
    }
    free(temp);
    return 1;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif