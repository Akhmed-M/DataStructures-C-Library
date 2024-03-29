#ifndef TYPE_H
#define TYPE_H

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef int Element; // Only thing that can change
// DO NOT CHANGE ANYTHING BELOW

// binary tree structure
typedef struct node
{
    Element data;
    struct node *left, *right;
} *BTree, node;

typedef BTree element; // NEVER CHANGE OR OVERRIDE `element`
typedef struct cell
{
    element data;
    struct cell *next;
} cell;

// Returns a new tree node filled with a given value
node *createNode(Element value)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (!newNode)
        return NULL;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

/*---------------------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------------------*/

#endif