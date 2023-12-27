# BFS
from collections import defaultdict, deque
def validPath(n: int, edges: List[List[int]], source: int, destination: int) -> bool:
    # adj_list = {i:[] for i in range(n)}
    graph = defaultdict(list)
    for v1,v2 in edges:
        graph[v1].append(v2)
        graph[v2].append(v1)
        
    # Queue for BFS -> Should start from source (=root)
    queue = deque()
    queue.append(source)
    visit = [0]*n
    while queue:
        curr = queue.popleft()
        if curr == destination:
            return True
        # If this node has been visited -> No need to 
        if visit[curr]:
            continue
        # Mark the node as visited
        visit[curr] = True
        # For all adjacent nodes
        for v in graph[curr]:
            if v == destination:
                return True
            elif not visit[v]:
                queue.append(v)
    return False   