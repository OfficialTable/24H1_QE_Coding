"""
    Graph traversal에 관한 코드.
    start node만 제시함.

    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')
    G = dict()
    G[A], G[B], G[C] = [C, D] , [A, E], [B, D]
    G[D], G[E], G[F] = [F], [F], []

    이거 형식 자체가 지금 directed graph임.

    find root vertices는 한 node에서 bfs, dfs돌렸을 때 전부 다 도는 노드를 말함.
"""

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
        return self.id
  
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

def _bfs(G: dict, s: GNode):
    queue = [s]
    path = []
    s.color = "G"

    while queue:
        node = queue.pop(0)
        # print(node.id)
        path.append(node.id)

        for neigh in G[node]:
            if neigh.color == "W":
                neigh.color = "G"
                neigh.parent = node
                queue.append(neigh)
        node.color = "B"
    return path

def _dfs(G: dict, s: GNode):
    stack = [s]
    path = []
    s.color = "G"

    while stack:
        node = stack.pop()
        path.append(node.id)

        for neigh in G[node]:
            if neigh.color == "W":
                neigh.color = "G"
                neigh.parent = node
                stack.append(neigh)
        node.color = "B"
    return path

def graph_reset(G: dict):
    for node in G.keys():
        node.color = "W"
        node.parent = None
    return None

############################################################

## find_root_veritices function 
def find_root_vertices (G):
    root_list = []
    key_list = []
    #모든 노드를 포함한 리스트
    for key in G.keys():
        key_list.append(key.id)
    key_list = sorted(key_list)
    # print("key_list: ", key_list)

    for key in G.keys():
        # print("#####", key.id, "#####")
        #하나씩 넣어주면서 bfs 구하기 ---------------------------------------------------------여기를 그냥 _dfs(G, key) 로 바꿔주면 simply done--------------------------
        target_path = _bfs(G, key)
        #bfs 돈 게 모든 노드를 포함한 리스트와 같으면
        if sorted(target_path) == key_list:
            #root에다가 해당 키를 넣어주기
            root_list.append(key.id)
        #다시 visited list (색깔 ) 초기화
        graph_reset(G)

    return root_list

# Driver Code
if __name__ == '__main__':

    print("test1")
    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')
    G = dict()
    G[A], G[B], G[C] = [C, D] , [A, E], [B, D]
    G[D], G[E], G[F] = [F], [F], []

    print("GNODE: " , _show_GNode(G))

    res1 = find_root_vertices(G)
    """
    실험해볼때 사이에 reset을 껴주어야함~
    print("dfs", _dfs(G, A))
    graph_reset(G)
    print("bfs", _bfs(G, A))
    """
    print(res1)

    print("test2")

    A, B, C = GNode('A'), GNode('B'), GNode('C')
    D, E, F = GNode('D'), GNode('E'), GNode('F')
    G = dict()
    G[A], G[B], G[C] = [D] , [E], [B, D]
    G[D], G[E], G[F] = [F], [F], []

    print("GNODE: " , _show_GNode(G))

    res2 = find_root_vertices(G)
    print(res2)