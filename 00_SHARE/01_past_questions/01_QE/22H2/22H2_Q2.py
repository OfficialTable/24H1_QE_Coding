## Q2 ##
class GNode:
  def __init__(self, id):
    self.id = id
  
  def __str__(self):
    return self.id
  
def paths(G, s, t):
    paths = []

    def dfs(curr, path):
        #현재 노드가 목표 노드인 경우
        if curr.id == t.id:
            #경로를 paths 리스트에 추가한다
            paths.append(path + [curr.id])
        else:
            #현재 노드의 이웃들에 대해 이를 반복
            for neighbor in G[curr]:
                dfs(neighbor, path + [curr.id])
    
    dfs(s, [])
    return paths

# Driver Code
if __name__ == '__main__':

    a, b, c, d = GNode('a'), GNode('b'), GNode('c'), GNode('d')
    G = dict()
    G[a], G[b], G[c], G[d] = [b, c], [d], [], [c]

    print(paths(G, a, c)) # [['a', 'b', 'd', 'c'], ['a', 'c']]
