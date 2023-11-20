def longestPalindrome(s: str) -> str:
    idx_length = len(s)
    memo = [0] * (idx_length+1) # make memoization space for all characters
    inverse = s[::-1]
    for i in range(1, idx_length+1):
        prev = [0] * (idx_length+1)
        for j in range(1, idx_length+1):
            if s[i-1] == inverse[j-1]:
                memo[j] = 1+prev[j-1]
            else:
                memo[j] = max(prev[j], memo[j-1])
        prev = memo[:]
       
    return prev[idx_length]