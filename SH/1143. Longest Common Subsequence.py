# using 2D DP
def longestCommonSubsequence(self, text1: str, text2: str) -> int:
	dp = [[0 for j in range(len(text2+1)] for i in range(len(text1)+1)]
	# Configuration of dp table
	for i in range(len(text1)-1, -1, -1):
		for j in range(len(text2)-1, -1, -1):
			if text1[i] == text2[j]:
				dp[i][j] = 1+ dp[i+1][j+1]
			else:
				dp[i][j] = max(dp[i][j+1], dp[i+1][j]) # Not adding any, just want to find the longest on
	return dp[0][0]

# Using two pointer
def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = map(len, (text1, text2))
        if m < n:
            tex1, tex2 = text2, text1
        dp = [0] * (n + 1)
        for c in text1:
            prevRow, prevRowPrevCol = 0, 0
            for j, d in enumerate(text2):
                prevRow, prevRowPrevCol = dp[j + 1], prevRow
                dp[j + 1] = prevRowPrevCol + 1 if c == d else max(dp[j], prevRow)
        return dp[-1]