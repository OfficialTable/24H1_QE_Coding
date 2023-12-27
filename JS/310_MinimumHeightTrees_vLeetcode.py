class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        #0 edge case
        if n == 1: 
            return [0]

        #1 dfs function
        def dfs(node, parent, curr, visited):
            dist[parent] = max(dist[parent], curr)
            for neign in graph[node]:
                if neign not in visited:
                    visited.add(neign)
                    dfs(neign, parent, curr + 1, visited)
                    visited.discard(neign)

        #2 variable setting and make graph
        graph = defaultdict(list)
        nodes = set()
        res = set()

        for a, b in edges:
            nodes.add(a)
            nodes.add(b)
            graph[a].append(b)
            graph[b].append(a)
        dist = defaultdict(int)
        
        #3 find min height using dfs function
        for node in nodes:
            dfs(node, node, 0, {node})
        min_height = min(dist.values())
        for k, v in dist.items():
            if v == min_height:
                res.add(k)
        
        return res