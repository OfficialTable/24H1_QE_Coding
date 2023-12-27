class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        ##그래프의 순환여부를 판별하는 문제임!##
        
        """그래프 생성"""
        graph = {}
        in_degree = [0] * numCourses

        for course, prereq in prerequisites:
            if prereq not in graph:
                graph[prereq] = []
            graph[prereq].append(course)
        
        visited = [0] * numCourses  # 0: not visited, 1: visiting, 2: visited

        def dfs(course):
            if visited[course] == 1:
                return False  # 순환 발견
            if visited[course] == 2:
                return True  # 이미 방문한 노드인 경우

            visited[course] = 1  # 방문 중으로 표시

            if course in graph:
                for neighbor in graph[course]:
                    if not dfs(neighbor):
                        return False  # 순환 발견 시 종료

            visited[course] = 2  # 방문 완료로 표시
            return True

        for course in range(numCourses):
            if visited[course] == 0:  # 아직 방문하지 않은 노드에 대해 DFS 수행
                if not dfs(course):
                    return False  # 순환 발견 시 종료

        return True