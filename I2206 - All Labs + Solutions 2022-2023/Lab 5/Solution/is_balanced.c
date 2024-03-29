#include "./Tools/BTree_Tools.c"

int is_balanced(BTree root)
{
    if (!root)
        return 1; // empty = balanced
    if (abs(delta_heights(root)) > 1)
        return 0;
    return is_balanced(root->left) && is_balanced(root->right);
}