#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

typedef struct AdjList {
    struct AdjListNode* head;
} AdjList;

typedef struct Graph {
    int numVertices;
    struct AdjList* array;
} Graph;

AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));

    for (int i = 0; i < numVertices; ++i) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

bool DFSUtil(int u, bool visited[], Graph* graph, int destination) {
    visited[u] = true;

    if (u == destination) 
        return true;

    AdjListNode* node = graph->array[u].head;
    while (node != NULL) {
        if (!visited[node->dest]) {
            if (DFSUtil(node->dest, visited, graph, destination)) 
                return true;
        }
        node = node->next;
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    Graph* graph = createGraph(n);

    for (int i = 0; i < edgesSize; i++) {
        int src = edges[i][0];
        int dest = edges[i][1];
        addEdge(graph, src, dest);
    }

    bool* visited = (bool*)malloc(n * sizeof(bool));
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    bool result = DFSUtil(source, visited, graph, destination);

    free(visited);
    return result;
}