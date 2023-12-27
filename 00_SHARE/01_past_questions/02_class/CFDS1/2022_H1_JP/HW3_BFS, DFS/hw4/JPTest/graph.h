#pragma once

#include <string>
#include <vector>

class Vertex {
public:
  Vertex(std::string name) {
    name_ = name;
  }

  std::string GetName() { return name_; }
  std::vector<Vertex*> GetAdjacencyList() { return adjacency_list_; }

  void AddToAdjacentList(Vertex* vertex);

private:
  std::string name_;
  std::vector<Vertex*> adjacency_list_; // basket for adjacency vertex & std::vector class
};

class Graph {
public:
  Graph() {}
  ~Graph();

  Vertex* GenVertex(std::string name);
  void GenEdge(Vertex* start, Vertex* end);

  std::vector<Vertex*> GetVertices() { return vertices_; }
  size_t GetNumVertices() { return vertices_.size(); }

  void PrintGraph();

private:
  std::vector<Vertex*> vertices_;
};
