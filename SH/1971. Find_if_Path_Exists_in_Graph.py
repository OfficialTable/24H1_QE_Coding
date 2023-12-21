class Solution:
    def validPath(self, n: int, edges: List[List[int]], src: int, des: int) -> bool:
        graph = [[] for _ in range(n)]
        for edge in edges:
            src1, des1 = edge
            src2, des2 = edge[::-1]
            graph[src1].append(des1)
            graph[src2].append(des2)
        
        visited = set()
        def has_path(node):
            if node == des:
                return True
            visited.add(node)
            for neighbor in graph[node]:
                if neighbor not in visited:
                    if has_path(neighbor):
                        return True
            return False
        return has_path(src)