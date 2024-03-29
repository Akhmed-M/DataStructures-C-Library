#include "./Tools/DataStructures/Type.h"

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

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
// TEST

BTree test_tree()
{
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
    */

    BTree root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    return root;
}

void main()
{
    BTree root = test_tree();
    BTree first, second, LCA;

    first = root->left->left;   // 4
    second = root->left->right; // 5
    LCA = least_common_ancestor(root, first, second);
    printf("Least common ancestor of `%d` and `%d` (test 1) = %d\n", first->data, second->data, LCA->data);
    // EXPECTED OUTPUT = 2

    first = root->left->right;  // 5
    second = root->right->left; // 6
    LCA = least_common_ancestor(root, first, second);
    printf("Least common ancestor of `%d` and `%d` (test 2) = %d\n", first->data, second->data, LCA->data);
    // EXPECTED OUTPUT = 1
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
