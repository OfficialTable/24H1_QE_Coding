/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct QueueNode {
    struct TreeNode* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* queue, struct TreeNode* item);
struct TreeNode* dequeue(Queue* queue);
bool isQueueEmpty(Queue* queue);
int queueSize(Queue* queue);

// Zigzag level order traversal function
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    int** results = (int**)malloc(1000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;

    Queue* queue = createQueue();
    enqueue(queue, root);
    bool l_to_r = true;

    while (!isQueueEmpty(queue)) {
        int levelSize = queueSize(queue);
        (*returnColumnSizes)[*returnSize] = levelSize;
        results[*returnSize] = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(queue);

            int index = l_to_r ? i : (levelSize - 1 - i);
            results[*returnSize][index] = node->val;

            if (node->left) enqueue(queue, node->left);
            if (node->right) enqueue(queue, node->right);
        }

        (*returnSize)++;
        l_to_r = !l_to_r;
    }

    return results;
}

// Queue implementation
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, struct TreeNode* item) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = item;
    temp->next = NULL;

    if (queue->rear == NULL) {
        queue->front = queue->rear = temp;
        return;
    }

    queue->rear->next = temp;
    queue->rear = temp;
}

struct TreeNode* dequeue(Queue* queue) {
    if (queue->front == NULL) return NULL;

    QueueNode* temp = queue->front;
    struct TreeNode* treeNode = temp->treeNode;
    queue->front = queue->front->next;

    if (queue->front == NULL) queue->rear = NULL;

    free(temp);
    return treeNode;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

int queueSize(Queue* queue) {
    int size = 0;
    QueueNode* temp = queue->front;
    while (temp) {
        size++;
        temp = temp->next;
    }
    return size;
}