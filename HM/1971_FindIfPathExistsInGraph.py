###############BFS approach##############
def validPath(self, n, edges, source, destination):
    """
    :type n: int
    :type edges: List[List[int]]
    :type source: int
    :type destination: int
    :rtype: bool
    """
    # Create the graph as an adjacency list
    Graph = defaultdict(list)
    for u, v in edges:
        Graph[u].append(v)
        Graph[v].append(u)

    # Perform BFS to check if there is a path from source to destination
    visited = set()
    queue = [source]

    while queue:
        node = queue.pop(0)

        if node == destination:
            return True  # Path found

        if node not in visited:
            visited.add(node)
            queue.extend(Graph[node])

    return False  # No path found

################DFS approach#############
def validPath(self, n, edges, source, destination):
    """
    :type n: int
    :type edges: List[List[int]]
    :type source: int
    :type destination: int
    :rtype: bool
    """
    # Create the graph as an adjacency list
    Graph = defaultdict(list)
    for u, v in edges:
        Graph[u].append(v)
        Graph[v].append(u)

    visited = set()

    def dfs(node):
        if node == destination:
            return True

        visited.add(node)

        for neighbor in Graph[node]:
            if neighbor not in visited:
                if dfs(neighbor):
                    return True

        return False

    return dfs(source)