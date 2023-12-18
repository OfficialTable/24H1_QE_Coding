#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to find the maximum depth of a binary tree
int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    // Example usage for LeetCode 104
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    int depth = maxDepth(root);
    printf("Maximum Depth: %d\n", depth);

    // Free allocated memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
