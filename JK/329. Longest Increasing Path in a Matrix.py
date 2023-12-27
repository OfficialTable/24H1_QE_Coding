def longestIncreasingPath(matrix):
    if not matrix or not matrix[0]:
        return 0

    def dfs(i, j):
        if memo[i][j]:
            return memo[i][j]

        length = 1
        for d in range(4):
            next_r, next_c = i + dr[d], j + dc[d]
            if 0 <= next_r < rows and 0 <= next_c < cols and matrix[next_r][next_c] > matrix[i][j]:
                length = max(length, 1 + dfs(next_r, next_c))

        memo[i][j] = length
        return length

    rows, cols = len(matrix), len(matrix[0])
    memo = [[0] * cols for _ in range(rows)]

    dr = [1, -1, 0, 0]
    dc = [0, 0, 1, -1]

    max_path = 0
    for i in range(rows):
        for j in range(cols):
            max_path = max(max_path, dfs(i, j))

    return max_path
        