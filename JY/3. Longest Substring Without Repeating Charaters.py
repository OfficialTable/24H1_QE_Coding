class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ###sliding window 기법###
        distinct_alphabet = set()
        start = 0
        max_length = 0

        for i in range(len(s)):
            while s[i] in distinct_alphabet:
                distinct_alphabet.remove(s[start])
                start += 1
            distinct_alphabet.add(s[i])
            max_length = max(max_length, i-start +1)

        return max_length