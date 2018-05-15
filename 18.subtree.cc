#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
using namespace base;

bool is_subtree(TreeNode *t1, TreeNode *t2);
bool is_same_root_subtree(TreeNode *t1, TreeNode *t2);
int main(void)
{
    int data[] = {8, 8, 7, 9, 2, 4, 7};
    TreeNode node[7];
    for (int i = 0; i < 7; ++i) {
        node[i].data = data[i];
        node[i].left = NULL;
        node[i].right = NULL;
    }
    node[0].left = &node[1];
    node[0].right = &node[2];
    node[1].left = &node[3];
    node[1].right = &node[4];
    node[4].left = &node[5];
    node[4].right = &node[6];
    printf("%d", is_subtree(&node[0], &node[1]));
    printf("%d", is_subtree(&node[0], NULL));
}

bool is_subtree(TreeNode *t1, TreeNode *t2)
{
    if (NULL == t2)
        return true;

    if (NULL == t1) {
        return false;
    }

    bool result = false;
    if (t1->data == t2->data) {
        result = is_same_root_subtree(t1, t2);
    }

    if (!result) {
        result = is_subtree(t1->left, t2) || is_subtree(t1->right, t2);
    }

    return result;
}

bool is_same_root_subtree(TreeNode *t1, TreeNode *t2)
{
    if (NULL == t2)
        return true;

    if (NULL == t1) {
        return false;
    }

    if (t1->data == t2->data) {
        return is_same_root_subtree(t1->left, t2->left) && is_same_root_subtree(t1->right, t2->right);
    } else {
        return false;
    }

}
