from collections import defaultdict, deque

class Solution(object):
    def validPath(self, n, edges, source, destination):
        """
        :type n: int
        :type edges: List[List[int]]
        :type source: int
        :type destination: int
        :rtype: bool
        """

        """그래프 생성방법 1"""
        graph = {}

        for edge in edges:
            u, v = edge
            if u not in graph:
                graph[u] = []
            if v not in graph:
                graph[v] = []
            graph[u].append(v)
            graph[v].append(u)
        
        """ 그래프 생성방법 2
        graph = defaultdict(list)

        for edge in edges:
            u, v = edge
            graph[u].append(v)
            graph[v].append(u)"""

        visited = set()

        # DFS 
        return self.dfs(graph, source, destination, visited)

    def dfs(self, graph, current, destination, visited):
        
        if current == destination:
            return True

        visited.add(current)

        # 현재의 이웃방문
        for neighbor in graph[current]:
            if neighbor not in visited:
                if self.dfs(graph, neighbor, destination, visited):
                    return True

        # DFS 다 돌고 나서도 도착못하면, return False
        return False