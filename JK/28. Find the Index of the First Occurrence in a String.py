
def strStr(haystack: str, needle: str) -> int:
    ans = -1
    if needle in haystack:
        for i in range(len(haystack)):
            if needle == haystack[i:i+len(needle)]:
                ans = i
                break

                

    return ans