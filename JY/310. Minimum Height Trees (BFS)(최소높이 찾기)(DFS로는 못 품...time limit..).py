from collections import defaultdict, deque

class Solution(object):
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """

        # 노드 하나일때. root
        if n == 1:
            return [0]

        #그래프 초기화 방법 1 graph = defaultdict(list)
        #그래프 초기화 방법 2
        graph = {i: [] for i in range(n)}
        
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])

        # BFS (leave -> center).
        leaves = deque()
        for node in range(n):
            if len(graph[node]) == 1:
                leaves.append(node)

        while n > 2:
            # 최대 두개노드 남을때까지 leaves를 층 단위로 제거
            num_leaves = len(leaves)
            n -= num_leaves
            for i in range(num_leaves):
                leaf = leaves.popleft()
                neighbor = graph[leaf].pop()
                graph[neighbor].remove(leaf)
                if len(graph[neighbor]) == 1:
                    leaves.append(neighbor)

        return list(leaves)