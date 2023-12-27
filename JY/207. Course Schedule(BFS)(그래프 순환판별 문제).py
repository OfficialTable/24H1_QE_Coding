from collections import defaultdict, deque

class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        ##그래프의 순환여부를 판별하는 문제임!##
        
        """그래프 생성방법 1"""
        graph = {}
        in_degree = [0] * numCourses

        for course, prereq in prerequisites:
            if prereq not in graph:
                graph[prereq] = []
            graph[prereq].append(course)
            in_degree[course] += 1
        
        # 선행 과목이 없는 코스에 대한 정보 추가 (이거 없으면 keyerror)
        for course in range(numCourses):
            if course not in graph:
                graph[course] = []

        """그래프 생성방법 2
        graph = defaultdict(list)
        in_degree = [0] * numCourses

        for course, prereq in prerequisites:
            graph[prereq].append(course)
            in_degree[course] += 1"""

        # topological sort using BFS
        queue = deque()

        for course in range(numCourses):
            if in_degree[course] == 0:
                queue.append(course)

        while queue:
            current_course = queue.popleft()
            for neighbor in graph[current_course]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)

        # 모든 코스 확인했는지 체크
        return all(in_degree[course] == 0 for course in range(numCourses))