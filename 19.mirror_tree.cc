#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace base;

void mirror_tree(TreeNode *root);
void mirror_tree_with_queue(TreeNode *root);
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

    mirror_tree(&node[0]);
    printPreorder(&node[0]);
    printf("\n");
    mirror_tree(&node[0]);
    mirror_tree_with_queue(&node[0]);
    printPreorder(&node[0]);
}

void mirror_tree(TreeNode *root)
{
    if (NULL == root)
        return;

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror_tree(root->left);
    mirror_tree(root->right);
}

void mirror_tree_with_queue(TreeNode *root)
{
    if (NULL == root)
        return;

    std::queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        TreeNode *tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;

        if (NULL != cur->left)
            q.push(cur->left);
        if (NULL != cur->right)
            q.push(cur->right);
    }
}
