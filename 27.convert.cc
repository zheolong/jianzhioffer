#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace base;

TreeNode *convert(TreeNode *root);
void convert_core(TreeNode *cur_node, TreeNode **last_node);
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

    TreeNode *p = convert(&node[0]);
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->right;
    }
}

TreeNode *convert(TreeNode *root)
{
    if (root == NULL)
        return root;

    TreeNode *last_node = NULL;
    convert_core(root, &last_node);
    
    TreeNode *new_head = last_node;
    while (new_head->left != NULL) {
        new_head = new_head->left;
    }

    return new_head;
}

void convert_core(TreeNode *cur_node, TreeNode **last_node)
{
    if (cur_node == NULL)
        return;
 
    if (cur_node->left !=NULL)
        convert_core(cur_node->left, last_node);

    cur_node->left = *last_node;
    if (*last_node != NULL)
        (*last_node)->right = cur_node;

    *last_node = cur_node;

    if (cur_node->right != NULL)
        convert_core(cur_node->right, last_node);
}
