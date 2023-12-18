from collections import defaultdict

def findMinHeightTrees(n: int, edges: List[List[int]]) -> List[int]:

    if n == 1:
        return [0]  # Only one node, so the root is the only solution

    # Build the graph
    graph = defaultdict(list)
    for edge in edges:
        u, v = edge
        graph[u].append(v)
        graph[v].append(u)

    #가장 많이 연결되어 있는 노드가 루트가 되어야 최소 높이 트리를 만들 수 있음. 순차적으로 리프노드와 가까운 노드들을 제거해나간다.

    #리프노드를 제거해나간다. 
    leaves = []
    for i in range(n+1):
        #해당 키의 value가 하나면 리프노드.
        if len(graph[i]) == 1:
            leaves.append(i)

    """
    n은 전체 노드의 개수이므로 여기서 leaves, 즉 리프 노드의 개수만큼 계속 빼나가면서 최종 2개 이하가 남을 때까지 반복한다. 마지막에 남은 값이 홀수 개일 때는 루트가 최종 1개가 되지만, 짝수 개일 때는 2개가 될 수 있다. 
    따라서 while 반복문은 2개까지는 계속 반복한다. 리프 노드는 반복하면서 제거한다. 그래프 딕셔너리에서 pop()으로 제거하고, 연결된 값도 찾아서 제거한다. 
    즉 무방향 그래프라 그래프를 각각 두 번씩 만들었으므로 제거 또한 두 번씩 진행한다. 이제 마찬가지로 값이 1개뿐일 때는 리프 노드라는 의미이므로, 새로운 리프 노드를 new_Leaves로 구성하여 교체한다.
    """
    #계속해서 연결작은 애들 없애기. 최종 2개 이하가 남을 때까지 반복 (홀수면 바로 루트지만 짝수일 수도 있기에)
    while n > 2:
        n = n - len(leaves)
        new_leaves = []
        for leaf in leaves:
            neighbor = graph[leaf].pop()
            graph[neighbor].remove(leaf)

            if len(graph[neighbor]) == 1:
                new_leaves.append(neighbor)

        leaves = new_leaves

    return leaves