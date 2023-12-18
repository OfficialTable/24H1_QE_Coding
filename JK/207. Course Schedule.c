#include <stdbool.h>
#include <stdlib.h>

// Define a structure for the adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Define a structure for the adjacency list
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // Create an array of adjacency lists
    graph->array = (AdjList*)malloc(numVertices * sizeof(AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// DFS function to check for cycles in the graph
bool isCyclicUtil(Graph* graph, int v, bool visited[], bool* recStack) {
    if (visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        AdjListNode* node = graph->array[v].head;
        while (node != NULL) {
            if (!visited[node->dest] && isCyclicUtil(graph, node->dest, visited, recStack)) {
                return true;
            } else if (recStack[node->dest]) {
                return true;
            }
            node = node->next;
        }
    }

    recStack[v] = false;
    return false;
}

// Function to check if the graph contains a cycle
bool isCyclic(Graph* graph) {
    bool* visited = (bool*)malloc(graph->numVertices * sizeof(bool));
    bool* recStack = (bool*)malloc(graph->numVertices * sizeof(bool));

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < graph->numVertices; i++) {
        if (isCyclicUtil(graph, i, visited, recStack)) {
            return true;
        }
    }

    return false;
}

// Function to check if all courses can be finished
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    Graph* graph = createGraph(numCourses);
    for (int i = 0; i < prerequisitesSize; i++) {
        addEdge(graph, prerequisites[i][0], prerequisites[i][1]);
    }

    if (isCyclic(graph)) {
        return false;
    }
    return true;
}