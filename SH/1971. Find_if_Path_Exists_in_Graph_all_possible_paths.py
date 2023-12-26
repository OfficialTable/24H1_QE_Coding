# Adjacency matrix
def validPath(n: int, graph: List[List[int]], source: int, destination: int):
    paths, targets = [[source]], []
    while paths:
        path = paths.pop(0)
        edges = graph[path[-1]]
        if not edges:
            continue
        for edge in edges:
            if edge == destination:
                targets.append(path+[edge])
            else:
                paths = [path+[edge]] + paths
    return targets