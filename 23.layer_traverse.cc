#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <stack>
using namespace base;

void layer_traverse(TreeNode *root);
void pre_traverse(TreeNode *root);
void in_traverse(TreeNode *root);
void post_traverse(TreeNode *root);
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

    layer_traverse(&node[0]);
    printf("\n");
    pre_traverse(&node[0]);
    printf("\n");
    in_traverse(&node[0]);
    printf("\n");
    post_traverse(&node[0]);
    printf("\n");
}

void layer_traverse(TreeNode *root)
{
    if (NULL == root)
        return;

    std::queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode *cur = q.front();
        q.pop();
        printf("%d ", cur->data);

        if (NULL != cur->left)
            q.push(cur->left);
        if (NULL != cur->right)
            q.push(cur->right);
    }
}

void pre_traverse(TreeNode *root)
{
    if (NULL == root)
        return;

    std::stack<TreeNode *> s;
    s.push(root);
    TreeNode *p;
    while(!s.empty()) {
        p = s.top();
        s.pop();
        printf("%d ", p->data);
        if (p->right!=NULL)
            s.push(p->right);
        if (p->left!=NULL)
            s.push(p->left);
    }
}

void in_traverse(TreeNode *root)
{
    if (NULL == root)
        return;

    std::stack<TreeNode *> s;
    TreeNode *p = root;
    while(!s.empty() || p != NULL) {
        if (p != NULL) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            printf("%d ", p->data);
            p = p->right;
        }
    }
}

void post_traverse(TreeNode *root)
{
    if (NULL == root)
        return;

    std::stack<TreeNode *> s;
    TreeNode *p = root;
    TreeNode *q;
    do {
        while (p != NULL) {
            s.push(p);
            p = p->left;
        }

        TreeNode *q = NULL;
        while (!s.empty()) {
            p = s.top();
            if (p->right == q) {
                printf("%d ", p->data);
                s.pop();
                q = p;
            } else {
                p = p -> right;
                break;
            }
        }
    } while(!s.empty());
}
