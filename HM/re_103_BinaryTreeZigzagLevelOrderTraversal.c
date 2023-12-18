#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition for a queue node.
struct QueueNode {
    struct TreeNode* node;
    struct QueueNode* next;
};

struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to initialize a new queue
struct Queue* initQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a node to the queue
void enqueue(struct Queue* q, struct TreeNode* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue a node from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    struct QueueNode* temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    struct TreeNode* node = temp->node;
    free(temp);
    return node;
}

// Function to perform Zigzag Level Order Traversal
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (root == NULL) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct Queue* q = initQueue();
    enqueue(q, root);

    int** result = (int**)malloc(sizeof(int*));
    *returnColumnSizes = (int*)malloc(sizeof(int));

    *returnSize = 0;

    while (q->front != NULL) {
        int levelSize = q->rear - q->front + 1;
        int* levelValues = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            levelValues[i] = node->val;

            if (node->left != NULL) {
                enqueue(q, node->left);
            }

            if (node->right != NULL) {
                enqueue(q, node->right);
            }
        }

        if (*returnSize % 2 == 1) {
            // Reverse the values for odd levels (0-based index)
            int i = 0, j = levelSize - 1;
            while (i < j) {
                int temp = levelValues[i];
                levelValues[i] = levelValues[j];
                levelValues[j] = temp;
                i++;
                j--;
            }
        }

        result = (int**)realloc(result, (*returnSize + 1) * sizeof(int*));
        (*returnColumnSizes) = (int*)realloc(*returnColumnSizes, (*returnSize + 1) * sizeof(int));
        result[*returnSize] = levelValues;
        (*returnColumnSizes)[*returnSize] = levelSize;
        (*returnSize)++;
    }

    return result;
}
