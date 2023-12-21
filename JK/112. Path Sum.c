/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Definition for a node in the queue.
typedef struct QueueNode {
    struct TreeNode* treeNode;
    int currentSum;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

// Function prototypes for queue operations
Queue* createQueue();
void enqueue(Queue* queue, struct TreeNode* item, int currentSum);
QueueNode* dequeue(Queue* queue);
bool isQueueEmpty(Queue* queue);

// Function to check if tree has path sum
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }

    Queue* queue = createQueue();
    enqueue(queue, root, root->val);

    while (!isQueueEmpty(queue)) {
        QueueNode* node = dequeue(queue);
        struct TreeNode* treeNode = node->treeNode;
        int currentSum = node->currentSum;
        free(node);

        if (!treeNode->left && !treeNode->right && currentSum == targetSum) {
            return true;
        }

        if (treeNode->left) {
            enqueue(queue, treeNode->left, currentSum + treeNode->left->val);
        }
        if (treeNode->right) {
            enqueue(queue, treeNode->right, currentSum + treeNode->right->val);
        }
    }

    return false;
}

// Implementations of queue operations
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, struct TreeNode* item, int currentSum) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = item;
    newNode->currentSum = currentSum;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

QueueNode* dequeue(Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    QueueNode* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    return temp;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}