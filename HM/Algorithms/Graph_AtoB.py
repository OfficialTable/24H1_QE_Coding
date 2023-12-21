class GNode:
    def __init__(self, id, color = "W", p = None):
        '''
        [color spec]
        W: not visited
        G: visited but its neighbors are not visited 
        B: visited and all the neighbors are visited 
        '''
        self.id = id
        self.color = color
        self.parent = p

    def __str__(self):
        return str(self.id)
  
    def __hash__(self):
        return hash(self.id)
    
    def reset(self):
        self.id = id
        self.color = "W"
        self.parent = None

######################## utils ########################
def _show_GNode(G: dict) -> dict:
    #0. set params 
    res = {}
    for key in G.keys():
        key_id = key.id
        items_id_list = []
        for item in G[key]:
            items_id_list.append(item.id)
        # print(key_id)
        # print(items_id_list)
        res[key_id] = items_id_list
        # print(res)
    return res

def graph_reset(G: dict):
    for node in G.keys():
        node.color = "W"
        node.parent = None
    return None

def _bfs_paths(G: dict, start: GNode, target: GNode):
    queue = [(start, [start])]
    all_paths = []

    while queue:
        current_node, current_path = queue.pop(0)

        for neighbor in G[current_node]:
            if neighbor.color == "W":
                neighbor.color = "G"
                neighbor.parent = current_node
                queue.append((neighbor, current_path + [neighbor]))

        current_node.color = "B"

        if current_node == target:
            all_paths.append([node.id for node in current_path])

    # 모든 노드의 색상과 부모를 초기화합니다.
    for node in G:
        node.color = "W"
        node.parent = None

    return all_paths

def _dfs_paths(G: dict, start: GNode, target: GNode):
    stack = [(start, [start])]
    all_paths = []

    while stack:
        current_node, current_path = stack.pop()

        for neighbor in G[current_node]:
            if neighbor.color == "W":
                neighbor.color = "G"
                neighbor.parent = current_node
                stack.append((neighbor, current_path + [neighbor]))

        current_node.color = "B"

        if current_node == target:
            all_paths.append([node.id for node in current_path])

    # 모든 노드의 색상과 부모를 초기화합니다.
    for node in G:
        node.color = "W"
        node.parent = None

    return all_paths


    # Driver Code
if __name__ == '__main__':
    # 그래프 노드 초기화
    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')
    
    # 그래프 생성
    G = {
        A: [C, D],
        B: [A, E],
        C: [B, D],
        D: [F],
        E: [F],
        F: []
    }

    # 초기 그래프 상태 출력
    print("Initial GNODEs: ", _show_GNode(G))
    
    # BFS로 시작 노드 A에서 목표 노드 F까지의 모든 경로 찾기
    print("\nBFS Paths from A to F:")
    bfs_paths_A_to_F = _bfs_paths(G, A, F)
    print(bfs_paths_A_to_F)

    # BFS로 시작 노드 A에서 목표 노드 C까지의 모든 경로 찾기
    print("\nBFS Paths from A to C:")
    bfs_paths_A_to_C = _bfs_paths(G, A, F)
    for path in bfs_paths_A_to_C:
        print([node.id for node in path])

    graph_reset(G)
    # DFS로 시작 노드 A에서 목표 노드 C까지의 모든 경로 찾기
    print("\nDFS Paths from A to C:")
    dfs_paths_A_to_C = _dfs_paths(G, A, F)
    for path in dfs_paths_A_to_C:
        print([node.id for node in path])
