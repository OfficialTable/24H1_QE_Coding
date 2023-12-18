def validPath(n, edges, source, destination):
    if source == destination:
        return True

    adj_list = {}
    for i in range(n):
        adj_list[i] = []

    for a, b in edges:
        adj_list[a].append(b)
        adj_list[b].append(a)
    
    visited = set()

    def dfs(node):
        if node == destination:
            return True
        visited.add(node)
        for neighbour in adj_list[node]:
            if neighbour not in visited:
                if dfs(neighbour):
                    return True
        return False

    
    return dfs(source)