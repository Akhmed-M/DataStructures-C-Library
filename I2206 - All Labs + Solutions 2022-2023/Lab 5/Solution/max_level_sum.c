#include "./Tools/DataStructures/Queue.c"
#include "./Tools/BTree_Tools.c"
#include <limits.h>

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/

int max_level_sum(BTree root)
{
    if (root == NULL)
        return INT_MIN;
    if (isLeafNode(root))
        return root->data;
    queue q = CreateQueue();
    EnQueue(&q, root);

    int max_sum = root->data;
    int sum = 0; // sum of nodes in current level

    BTree e, first, next;
    first = root;
    while (Front(q, &e))
    {
        DeQueue(&q);
        if (e->left)
        {
            EnQueue(&q, e->left);
            sum += e->left->data;
        }
        if (e->right)
        {
            EnQueue(&q, e->right);
            sum += e->right->data;
        }
        // CHECK IF CURRENT LEVEL IS DONE
        if (Front(q, &next) && (next == first->right || next == first->left))
        {
            // UPDATE width
            if (sum > max_sum)
                max_sum = sum;
            // RESET
            sum = 0;
            first = next;
        }
    }
    return max_sum;
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// TEST

BTree test_tree_1()
{
    /*
              4
            /   \
           2    -5
          / \   / \
        -1   3 -2  6
    */
    BTree root = createNode(4);

    root->left = createNode(2);
    root->right = createNode(-5);

    root->left->right = createNode(3);
    root->left->left = createNode(-1);

    root->right->right = createNode(6);
    root->right->left = createNode(-2);

    return root;
}

BTree test_tree_2()
{
    /*
             1
           /   \
          2     3
         / \     \
        4   5     8
                 / \
                6   7
    */
    BTree root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    (root->left)->right = createNode(5);
    (root->left)->left = createNode(4);

    (root->right)->right = createNode(8);

    (root->right->right)->right = createNode(7);
    (root->right->right)->left = createNode(6);

    return root;
}

void main()
{
    BTree root_1 = test_tree_1();
    BTree root_2 = test_tree_2();

    printf("Max level sum (test 1) = %d\n", max_level_sum(root_1)); // 6
    printf("Max level sum (test 2) = %d\n", max_level_sum(root_2)); // 17
}

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/