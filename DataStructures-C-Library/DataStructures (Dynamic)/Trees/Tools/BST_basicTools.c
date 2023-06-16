#ifndef BST_ALLTOOLS_C
#define BST_ALLTOOLS_C

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// IMPORTS

// A binary-search-tree is a binary-tree
#include "../BinaryTree.c"
typedef BTree BST;

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// PROTO-TYPES

BST search_BST(BST root, treeElement targetValue);
BST min_BST(BST root);
BST max_BST(BST root);

int insert_BST(BST *root, treeElement value);
int isBST(BST root);

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

// Searches for a node inside a BST (returns null if not found)
BST search_BST(BST root, treeElement targetValue)
{
    if (!root || compareTreeElements(targetValue, root->data) == 0)
        return root; // empty or found
    if (compareTreeElements(targetValue, root->data) < 0)
        return search_BST(root->left, targetValue); // go left
    return search_BST(root->right, targetValue);    // go right
}

// Returns far left node in the tree (minimum)
BST min_BST(BST root)
{
    if (root == NULL || root->left == NULL)
        return root;            // empty or found
    return min_BST(root->left); // go left
}

// Returns far right node in the tree (maximum)
BST max_BST(BST root)
{
    if (root == NULL || root->right == NULL)
        return root;             // empty or found
    return max_BST(root->right); // go right
}

// Inserts a (distinct value) node according to sorted order of a BST
int insert_BST(BST *root, treeElement value)
{
    if (!root)
        return 0; // wrong input
    if (!(*root)) // empty or reached insert location
    {
        *root = createNode(value);
        return 1; // success
    }
    if (compareTreeElements(value, (*root)->data) == 0)
        return 0; // treeElement already exists
    if (compareTreeElements(value, (*root)->data) < 0)
        return insert_BST(&((*root)->left), value); // go left
    return insert_BST(&((*root)->right), value);    // go right
}

int isBST_rec(BST root, treeElement min, treeElement max)
{
    if (root == NULL)
        return 1; // empty or reached end
    if (compareTreeElements(root->data, max) >= 0 || compareTreeElements(root->data, min) < 0)
        return 0;
    return isBST_rec(root->left, min, root->data) && isBST_rec(root->right, root->data, max); // check left & right sub-trees
}
// left suBST: MUST(node<max) ==> INVERSE(node>=max)
// right suBST: MUST(node>=min) ==> INVERSE(node<min)

// Checks if a tree is a Binary Search Tree (BST)
int isBST(BST root)
{
    return isBST_rec(root, minLimit_treeElement(), maxLimit_treeElement());
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

#endif