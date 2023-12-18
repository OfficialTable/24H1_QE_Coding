#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to convert an integer to a string
char* intToString(int val) {
    char* str = (char*)malloc(12); // Sufficient for 32-bit integers
    sprintf(str, "%d", val);
    return str;
}

// Helper function to serialize the tree using preorder traversal
void serializeHelper(struct TreeNode* root, char* result) {
    if (root == NULL) {
        strcat(result, "null ");
        return;
    }

    // Convert the integer value to string and append to the result
    char* valStr = intToString(root->val);
    strcat(result, valStr);
    strcat(result, " ");

    // Recursively serialize the left and right subtrees
    serializeHelper(root->left, result);
    serializeHelper(root->right, result);
}

// Encodes a tree to a single string.
char* serialize(struct TreeNode* root) {
    // Allocate memory for the result string
    char* result = (char*)malloc(1024); // Adjust the size as needed
    result[0] = '\0'; // Initialize the result string

    // Start the serialization process
    serializeHelper(root, result);

    return result;
}

// Helper function to deserialize the tree
struct TreeNode* deserializeHelper(char** data) {
    // Extract the next token from the serialized string
    char* token = strtok(NULL, " ");

    if (token == NULL || strcmp(token, "null") == 0) {
        return NULL;
    }

    // Convert the string to an integer
    int val = atoi(token);

    // Create a new tree node with the current value
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;

    // Recursively deserialize the left and right subtrees
    newNode->left = deserializeHelper(data);
    newNode->right = deserializeHelper(data);

    return newNode;
}

// Decodes your encoded data to a tree.
struct TreeNode* deserialize(char* data) {
    // Use strtok to split the serialized string into tokens
    char* token = strtok(data, " ");

    // If the string is empty or "null", return NULL
    if (token == NULL || strcmp(token, "null") == 0) {
        return NULL;
    }

    // Convert the string to an integer
    int val = atoi(token);

    // Create the root node with the first value
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;

    // Recursively deserialize the left and right subtrees
    root->left = deserializeHelper(&token);
    root->right = deserializeHelper(&token);

    return root;
}


