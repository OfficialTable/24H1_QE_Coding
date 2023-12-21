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

typedef struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

// Function prototypes for queue operations
Queue* createQueue();
void enqueue(Queue* queue, struct TreeNode* item);
struct TreeNode* dequeue(Queue* queue);
int isQueueEmpty(Queue* queue);

// Function to calculate maximum depth of binary tree
int maxDepth(struct TreeNode* root) {
    if (!root) {
        return 0;
    }

    Queue* queue = createQueue();
    enqueue(queue, root);
    int depth = 0;

    while (!isQueueEmpty(queue)) {
        int level_size = 0;
        QueueNode* temp = queue->front;
        while (temp) {
            level_size++;
            temp = temp->next;
        }

        for (int i = 0; i < level_size; i++) {
            struct TreeNode* node = dequeue(queue);
            if (node->left) enqueue(queue, node->left);
            if (node->right) enqueue(queue, node->right);
        }

        depth++;
    }

    return depth;
}

// Implementations of queue operations
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, struct TreeNode* item) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = item;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

struct TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    QueueNode* temp = queue->front;
    struct TreeNode* node = temp->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return node;
}

int isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}