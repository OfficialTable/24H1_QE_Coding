/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if (n == 1) {
        int* result = (int*)malloc(sizeof(int));
        result[0] = 0;
        *returnSize = 1;
        return result;
    }

    int* graph[n];
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(sizeof(int));
        graph[i][0] = 0;
    }

    // Build the graph
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        graph[u] = (int*)realloc(graph[u], (graph[u][0] + 2) * sizeof(int));
        graph[v] = (int*)realloc(graph[v], (graph[v][0] + 2) * sizeof(int));

        graph[u][0]++;
        graph[v][0]++;

        graph[u][graph[u][0]] = v;
        graph[v][graph[v][0]] = u;
    }

    // Initialize leaves (nodes with only one connection)
    int* leaves = (int*)malloc(n * sizeof(int));
    int leavesCount = 0;

    for (int i = 0; i < n; i++) {
        if (graph[i][0] == 1) {
            leaves[leavesCount++] = i;
        }
    }

    // Remove leaves and update the graph until only 2 or fewer nodes are left
    while (n > 2) {
        n -= leavesCount;
        int* newLeaves = (int*)malloc(n * sizeof(int));
        int newLeavesCount = 0;

        for (int i = 0; i < leavesCount; i++) {
            int leaf = leaves[i];
            int neighbor = graph[leaf][1];

            // Remove the leaf from its neighbor's connections
            for (int j = 1; j <= graph[neighbor][0]; j++) {
                if (graph[neighbor][j] == leaf) {
                    for (int k = j; k < graph[neighbor][0]; k++) {
                        graph[neighbor][k] = graph[neighbor][k + 1];
                    }
                    graph[neighbor][0]--;
                    break;
                }
            }

            // If the neighbor becomes a leaf, add it to the new leaves array
            if (graph[neighbor][0] == 1) {
                newLeaves[newLeavesCount++] = neighbor;
            }
        }

        free(leaves);
        leaves = newLeaves;
        leavesCount = newLeavesCount;
    }

    *returnSize = leavesCount;
    return leaves;
}

