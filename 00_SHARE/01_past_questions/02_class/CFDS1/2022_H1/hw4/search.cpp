#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include "search.h"

void BFS(Vertex* start, std::map<Vertex*, unsigned int> &distance) {
  unsigned int curr;
  Vertex* vertex;
	std::queue<std::pair<Vertex*, unsigned int>> q;

  // boolean value is true when vertex is visited
  std::map<Vertex*, bool> visited;

  // root node has distance of zero
  curr = 0;
  
  // TODO: mark root node as visited
  visited[start] = true;

  // push (root node, distance 0) pair to the queue
	q.push(std::make_pair(start, curr));

	// loop utill the queue is empty
	while (q.empty() == false) {
    // lookup front of the queue
		vertex = q.front().first;
    curr = q.front().second;

    // TODO: pop out front of the queue
    q.pop();

    for (auto adjacent : vertex->GetAdjacencyList()) {
      // when adjacent vertex is not yet visited
      if (visited[adjacent] == false) {
        // TODO: mark adjacent vertex as visited
        visited[adjacent] = true;

        // TODO: push (adjacent vertex, distance) pair to the queue
        q.push(std::make_pair(adjacent, curr+1));
      }
    }

    // write distance of the vertex to the map
    distance[vertex] = curr;
	}
}

void DFS(Vertex* vertex, unsigned int &timestamp,
    std::map<Vertex*, unsigned int> &discovery_time,
    std::map<Vertex*, unsigned int> &finishing_time) {
  // TODO: increase timestamp for discovery time
  timestamp += 1;

  // TODO: store discovery time of current vertex
  discovery_time[vertex] = timestamp;

  // TODO: recursively call DFS for vertices in the adjancency list
  // vertex를 갯수만큼 다 돌아서 이제 finishing_time으로 넘어가기 전까지 DFS 돈다는 말이 있어야되는데
  // discovery_time = 0;

    for (auto adjacent : vertex->GetAdjacencyList()) {
      // when adjacent vertex is not yet visited
    if (discovery_time[adjacent] == false) {
        // TODO: mark adjacent vertex as visited
      discovery_time[adjacent] = true;
      DFS(adjacent, timestamp, discovery_time, finishing_time);
    }
    }
  // increase timestamp for finishing time
  timestamp += 1;

  // store finishing time of current vertex
  finishing_time[vertex] = timestamp;
}
