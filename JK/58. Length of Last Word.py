
def lengthOfLastWord(s: str) -> int:
    ans = 0

    for i in range(len(s)):
        if s[i] == ' ' and i < len(s)-1:
            if s[i+1] != ' ':
                ans=0

        elif s[i] != ' ':
            ans += 1



    return ans

    