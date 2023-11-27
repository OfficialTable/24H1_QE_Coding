## Author : Jeongsik Pyo
## Date   : 2023-09-19
## Lang   : Python

'''
Question 01 
Finding root vertices
'''

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
    return sorted(path)

def _bfs_reset(G: dict):
    for node in G.keys():
        node.color = "W"
        node.parent = None
    return None

############################################################

## find_rood_veritics function 
def find_root_vertices (G):
    root_list = []
    key_list = []
    for key in G.keys():
        key_list.append(key.id)
    key_list = sorted(key_list)
    # print("key_list: ", key_list)

    for key in G.keys():
        # print("#####", key.id, "#####")
        target_path = _bfs(G, key)
        if target_path == key_list:
            root_list.append(key.id)
        _bfs_reset(G)

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

