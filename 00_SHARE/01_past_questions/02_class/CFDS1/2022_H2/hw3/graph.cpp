#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*  Let's implement our class undi_graph that provides 
    (1) BFS, (2) DFS preorder, and (3) DFS postorder    */

/* Define undi_graph */
class undi_graph {
    int vNum;
    vector< vector<int> > neighbors;

public:
    undi_graph(const int& num, const vector< vector<int> >& edges);
    void visitAction(const int& v);

    void bfs(void);

    void dfs(const int& mode);
    void dfs_help(const int& mode, const int& v, vector<bool>& visited);
};

/* Construct a graph using vertices and edges */
undi_graph::undi_graph(const int& num, const vector< vector<int> >& edges) {
    vNum = num;
    cout << "&neighbors = " << &neighbors << endl;
    neighbors = vector< vector<int> >(num, vector<int>(0));
    for (int i=0; i<num; i++) {
        neighbors.push_back( vector<int>(0));
    }
    cout << "&neighbors = " << &neighbors << endl;

    for (int i=0; i < edges.size(); i++) { 
        /* if edges[i] is (u,v), add v to the u's neighbor list and
                                 add u to the v's neighbor list */
        neighbors[edges[i][0]].push_back(edges[i][1]);
        neighbors[edges[i][1]].push_back(edges[i][0]);
    }
}

/* Print the vertex on the screen */
void undi_graph::visitAction(const int& v) {
    cout << v << " ";
}

/* Visit all verices in the graph with breadth-first search */
void undi_graph::bfs(void) {
    vector<bool> visited(vNum, false);
    list<int> q;

    for (int v=0; v<vNum; v++) {
        q.push_back(v);
        int currV;

        while (!q.empty()) {
            currV = q.front();
            q.pop_front();

            if (!visited[currV]) {
                visited[currV] = true;
                visitAction(currV);

                for (const int& n : neighbors[currV]) {
                    q.push_back(n);
                }
            }
        }
    }
}

/* Visit all vertices in the graph with depth-first search */
void undi_graph::dfs(const int& mode) {
    vector<bool> visited(vNum, false);

    for (int v=0; v<vNum; v++) {
        dfs_help(mode, v, visited);
    }
}

/* Visit all the vertices that are connected to the input vertex "v" */
void undi_graph::dfs_help(const int& mode, const int& v, vector<bool>& visited) {
    if (!visited[v]) {
        visited[v] = true;
        if (mode == 0) {
            visitAction(v);
        }

        // visit v's neighbors
        for (const int& n : neighbors[v]) {
            dfs_help(mode, n, visited);
        }

        if (mode == 1) {
            visitAction(v);
        }
    }
}

int main(void) {
    // Graph construction using 10 vertices
    int myVNum = 10;
    vector<vector<int>> myEdges{
        {0,1}, {1,4}, {1,5}, {2,3}, {4,6}, {5,6}, {5,7}, {6,9}, {7,8}
    };
    undi_graph myGraph(myVNum, myEdges);

    cout << "[BFS] ";           // Breadth First Search
    myGraph.bfs();
    cout << endl;

    cout << "[DFS preorder] ";  // Depth First Search - Preorder
    myGraph.dfs(0);
    cout << endl;

    cout << "[DFS postorder] "; // Depth First Search - Postorder
    myGraph.dfs(1);
    cout << endl;

    return 0;
}