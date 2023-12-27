'''
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

'''

from utils.GNode_by_Thunder import GNode, _show_GNode

def canFinish(graph) -> bool: 

    def dfs_visit(node, path):
        if node.color == "G":
            return True  
        if node.color == "B":
            return False

        node.color = "G"
        for neighbor in graph.get(node, []):
            if dfs_visit(neighbor, path):
                return True

        node.color = "B"
        path.append(node.id)
        return False

    path = []
    for course in graph.keys():
        if dfs_visit(course, path):
            return False
    return True


if __name__ == "__main__":
    print("207_CourseSchedule.py")
    print("\nCase 1")
    # Example usage:
    numCourses = 4
    prerequisites = [['B', 'A'], ['C', 'A'], ['D', 'B'], ['D', 'C']]
    A, B, C, D = GNode('A'), GNode('B'), GNode('C'), GNode('D')
    G = dict()
    G[B] = [A]
    G[C] = [A]
    G[D] = [B, C]
    print(_show_GNode(G))
    result = canFinish(G)
    print(result)  # Output: ['A', 'B', 'D', 'C'] 