## Q2 ##
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        '''
        [color spec]
        W: not visited
        G: visited but its neighbors are not visited 
        B: visited and all the neighbors are visited 
        '''
        self.id = id        # id is a string
        self.color = color  # color (status) of node
        self.distance = d
        self.parent = p
  
    def __str__(self):
        return self.id
  
## utils
def show_GNode(G: dict) -> dict:
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

### (a)
def bfs(G: dict, s: GNode) -> None:
    queue = [s]
    s.color = "G"

    while queue:
        node = queue.pop(0)
        # print(node.id)
        for neigh in G[node]:
            if neigh.color == "W":
                neigh.color = "G"
                neigh.distance = node.distance + 1
                neigh.parent = node
                queue.append(neigh)
        node.color = "B"

    return None

### (b)
def level_partition(G: dict,s: GNode) -> list:

    #0. set params 
    level_dict = {}
    res = []
    
    #1. do bfs 
    bfs(G, s)

    #2. add distance
    for key in G.keys():
        # print(level_dict)
        if key.distance in level_dict:
            level_dict[key.distance].append(key.id)
        else:
            level_dict[key.distance] = [key.id]

    #3. change into list type
    for i in range(len(level_dict)):
        res.append(level_dict[i])
    
    return res

# Driver Code
if __name__ == '__main__':

    r, s, t, u, v = GNode('r'), GNode('s'), GNode('t'), GNode('u'), GNode('v')
    w, x, y = GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[s], G[t], G[u], G[v] = [s, v], [w, r], [w, x, u], [t, x, y], [r]
    G[w], G[x], G[y] = [s, t, x], [w, t, u, y], [x, u]

    print(show_GNode(G))
    # print(bfs(G, s))
    print(level_partition(G, s)) #[[s], [r, w] ,[v, t, x], [u, y]]
