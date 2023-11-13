def isSubsequence(s: str, t: str) -> bool:
    start_1, end_1 = 0, len(s)
    start_2, end_2 = 0, len(t)
    while(start_2<end_2 and start_1<end_1):
        if s[start_1] == t[start_2]:
            start_1 += 1
        start_2 += 1
    if start_1 == end_1:
            return True
    return False