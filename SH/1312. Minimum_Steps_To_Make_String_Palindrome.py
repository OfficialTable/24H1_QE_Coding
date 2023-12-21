class Solution:
    def minInsertions(self, s: str) -> int:
        dp = [[0 for _ in range(len(s))]for _ in range(len(s))]
        for left in range(len(s) - 1, -1, -1): 

                dp[left][left] = 1

                for right in range(left + 1, len(s)):

                    if s[left] == s[right]:
                        dp[left][right] = 2 + dp[left + 1][right - 1]
                    else:
                        dp[left][right] = max(dp[left + 1][right], dp[left][right - 1])

        return len(s) - dp[0][len(s) - 1]