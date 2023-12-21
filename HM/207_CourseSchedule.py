from collections import defaultdict

class Solution:
    def __init__(self):
        self.graph = defaultdict(list)

    def DFSUtil(self, u, color):
        color[u] = "Gray"
        
        for v in self.graph[u]:
            if color[v] == "Gray":
                return True
            if color[v] == "White" and self.DFSUtil(v, color) == True:
                return True

        color[u] = "Black"
        return False
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        color = ["White"] * numCourses

        if prerequisites:
            for [a, b] in prerequisites:
                self.graph[b].append(a)
        for i in range(numCourses):
            if color[i] == "White":
                if self.DFSUtil(i, color) == True:
                    return False
        return True