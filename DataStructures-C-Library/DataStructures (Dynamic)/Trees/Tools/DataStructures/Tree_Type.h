#ifndef TYPE_H
#define TYPE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include "../../Types(variable)/Int_Tree.h" // treeElement customized for `int` type
// #include "../../Types(variable)/Char_Tree.h" // treeElement customized for `char` type

// #include "../../Types(variable)/IntArray_Tree.h" // treeElement customized for `int*` type
// #include "../../Types(variable)/CharArray_Tree.h" // treeElement customized for `char*` type

// binary tree structure
typedef struct treeNode
{
    treeElement data;
    struct treeNode *left, *right;
} *BTree, treeNode;

typedef BTree DS_element;
typedef struct cell
{
    DS_element data;
    struct cell *next;
} cell;

// Returns a new tree node filled with a given value
treeNode *createNode(treeElement value)
{
    treeNode *newNode = (treeNode *)malloc(sizeof(treeNode));
    if (!newNode)
        return NULL;
    newNode->data = createTreeElement(value);
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

#endif