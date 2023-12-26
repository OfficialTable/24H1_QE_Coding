# Adjacency Matrix with DFS
def validPath(n: int, edges: List[List[int]], source: int, destination: int) -> bool:
    graph = [[] for _ in range(n)]
    # Matrix construction
    for edge in edges:
        graph[edge[0]].append(edge[1])
        graph[edge[1]].append(edge[0])
    # dfs
    visited = set()
    def dfs(node):
        # Base Case
        if node == destination:
            return True
        visited.add(node)
        for w in graph[node]:
            if w not in visited:
                if dfs(w):
                    return True
        return False
    return dfs(source)