def reverseWords(s: str) -> str:
    temp = s.split()
    res = ""
    for i in range(len(temp)-1, -1, -1):
        if res == "":
            res += temp[i]
        else:
            res = res + " " + temp[i]
    return res
