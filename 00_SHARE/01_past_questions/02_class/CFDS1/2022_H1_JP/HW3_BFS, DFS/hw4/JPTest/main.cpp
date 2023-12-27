#include "graph.h"
#include <cstdlib>
#include <iostream>

void ShowcaseGraph() {
  // generate graph instance that manages vertices and edges
  Graph graph;

  // generate vertices
  Vertex* vertex_u = graph.GenVertex("u");
  Vertex* vertex_v = graph.GenVertex("v");
  Vertex* vertex_w = graph.GenVertex("w");
  Vertex* vertex_x = graph.GenVertex("x");
  Vertex* vertex_y = graph.GenVertex("y");
  Vertex* vertex_z = graph.GenVertex("z");

  // generate edges
  graph.GenEdge(vertex_u, vertex_v);
  graph.GenEdge(vertex_u, vertex_x);
  graph.GenEdge(vertex_v, vertex_y);
  graph.GenEdge(vertex_w, vertex_y);
  graph.GenEdge(vertex_w, vertex_z);
  graph.GenEdge(vertex_x, vertex_v);
  graph.GenEdge(vertex_y, vertex_x);
  graph.GenEdge(vertex_z, vertex_z);

  // print all vertices and its their adjacency lists
  graph.PrintGraph();
}


int main() {
  ShowcaseGraph();
  return 0;
}

  