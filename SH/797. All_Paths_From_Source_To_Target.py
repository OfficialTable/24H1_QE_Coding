class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        source, target = 0, len(graph)-1
        paths, targets = [[source]], [] 
        while paths:
            # Go over all paths
            path = paths.pop(0) 
            # Latest node as curr edge
            edges = graph[path[-1]]
            if not edges:
                continue
            for edge in edges:
                # when we reach destination
                if edge==target:
                    # complete path
                    targets.append(path+[edge])
                else:
                    # expand the possible path
                    paths = [path+[edge]] + paths
        return targets

        