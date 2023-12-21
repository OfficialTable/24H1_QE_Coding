/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdio.h>
#include <stdlib.h>

// Function prototype for counting nodes
int countNodes(struct TreeNode* root);

// Recursive function to count nodes
int dfs(struct TreeNode* node) {
    if (!node) {
        return 0;
    }
    return 1 + dfs(node->left) + dfs(node->right);
}

int countNodes(struct TreeNode* root) {
    return dfs(root);
}