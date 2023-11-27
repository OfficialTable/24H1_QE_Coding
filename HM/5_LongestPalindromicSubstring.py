def longestPalindrome(s: str) -> str:
    res = ""
    resLen = 0

    for i in range(len(s)):
        #odd length e.g. "bab" 
        #i = center position 
        left, right = i, i
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if (right - left + 1) > resLen:
                res = s[left : right + 1]
                resLen = right - left + 1
            left -= 1
            right += 1
        
        #even length e.g. "cbbc"
        left, right = i, i + 1
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if (right - left + 1) > resLen:
                res = s[left : right + 1]
                resLen = right - left + 1
            left -= 1
            right += 1
    
    return res