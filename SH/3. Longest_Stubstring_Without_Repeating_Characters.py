class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        memo = {}
        count = 0
        l = 0
        for i in range(len(s)):
            # Sliding window by moving the pointer
            if s[i] not in memo:
                count = max(count, i-l+1)
            # if s[i] already seen
            else:
                if memo[s[i]] < l:
                    count = max(count, i-l+1)
                else:
                    l = memo[s[i]] + 1 # Moving the pointer
            memo[s[i]] = i # set the index as the value of string
        return count