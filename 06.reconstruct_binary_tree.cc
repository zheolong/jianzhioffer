#include "base/binary_tree.h"
#include <stdio.h>
#include <stdlib.h>
using namespace base;
TreeNode* reconstruct_binary_tree(int *preorder_start, 
        int *preorder_end,
        int *inorder_start, 
        int *inorder_end);

int main(void)
{
    int preorder[] = {1,2,4,7,3,5,6,8};
    int inorder[] = {4,7,2,1,5,3,8,6};
    TreeNode *root = reconstruct_binary_tree(preorder, preorder + 7, inorder, inorder + 7);
    printPreorder(root);
    printInorder(root);
}

TreeNode* reconstruct_binary_tree(int *preorder_start, 
        int *preorder_end,
        int *inorder_start, 
        int *inorder_end)
{
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->data = *preorder_start;
    root->left = root->right = NULL;

    if (preorder_start == preorder_end) {
        if ((inorder_start == inorder_end)
            && (*preorder_start == *inorder_start)) {
                return root;
        } else {
            printf("invalid");
            exit(EXIT_FAILURE);
        }
    }

    int *root_inorder = inorder_start;
    bool found_root_inorder = false;
    while (root_inorder <= inorder_end) {
        if (*root_inorder == root->data) {
            found_root_inorder = true;
            break;
        } else {
            root_inorder++;
        }
    }

    if (!found_root_inorder) {
        printf("invalid");
        exit(EXIT_FAILURE);
    }

    int left_len = root_inorder - inorder_start;
    if (left_len > 0)
        root->left = reconstruct_binary_tree(preorder_start + 1, preorder_start + left_len, inorder_start, root_inorder - 1);
    if (left_len < preorder_end - preorder_start)
        root->right = reconstruct_binary_tree(preorder_start + left_len + 1, preorder_end, root_inorder + 1, inorder_end);

    return root;
}
