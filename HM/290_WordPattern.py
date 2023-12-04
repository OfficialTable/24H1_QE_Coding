def wordPattern(pattern: str, s: str) -> bool:
    s = s.split()
    pattern = list(pattern)
    temp = dict()

    if len(set(pattern)) != len(set(s)) or len(pattern) != len(s):
        return False

    for i in range(len(s)):
        if s[i] not in temp:
            temp[s[i]] = pattern[i]
        elif temp[s[i]] != pattern[i]:
            return False

    return True
