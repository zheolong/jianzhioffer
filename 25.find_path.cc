#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace base;

void find_path(TreeNode *root, int target_num);
void find_path_core(TreeNode *root, std::vector<TreeNode *> path, int target_num, int cur_num);
void print_vector(std::vector<TreeNode *> path);
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

    find_path(&node[0],15);
    find_path(&node[0],22);
    find_path(&node[0],25);
}

void find_path(TreeNode *root, int target_num)
{
    if (NULL == root)
        return;

    std::vector<TreeNode *> path;
    find_path_core(root, path, target_num, 0);
}

void find_path_core(TreeNode *root, std::vector<TreeNode *> path, int target_num, int cur_num)
{
    cur_num += root->data;
    path.push_back(root);

    bool is_leaf = (root->left == NULL) && (root->right == NULL);
    if (is_leaf && cur_num == target_num) {
        print_vector(path);
    }

    if (root->left != NULL) {
        find_path_core(root->left, path, target_num, cur_num);
    }

    if (root->right != NULL) {
        find_path_core(root->right , path, target_num, cur_num);
    }

    cur_num -= root->data;
    path.pop_back();
}

void print_vector(std::vector<TreeNode *> path)
{
    std::vector<TreeNode *>::iterator iter = path.begin();
    for (; iter != path.end(); iter++) {
        printf("%d ", (*iter)->data);
    }
    printf("\n");
}
