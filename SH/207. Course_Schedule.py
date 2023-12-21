class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        #q = collections.deque(prerequisites) # As this is given in List form, this should not be in []
        visited = []
        adj = [[] for i in range(numCourses)] # neighbors of pre 
        deg_cnt = [0] * numCourses # degree count for each courses

        # Need to create an adjacency graph (neighbor not give in List form)
        for pair in prerequisites:
            course, pre = pair[0], pair[1]
            adj[pre].append(course)
            deg_cnt[course] += 1 # To see the cycle

        q = collections.deque()
        for i in range(numCourses):
            if deg_cnt[i] == 0:
                q.append(i)

        # Need to look whether there is a cycle in the graph or not 
        # All course should not have any cyclic dependencies -> use deg_cnt
        while q:
            v = q.popleft() # Give one vertex 
            visited.append(v)
            for w in adj[v]:
                deg_cnt[w] -= 1
                if deg_cnt[w] == 0:
                    q.append(w)

        return len(visited) == numCourses


