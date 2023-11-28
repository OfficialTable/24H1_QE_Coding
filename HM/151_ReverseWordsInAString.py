def reverseWords(s: str) -> str:
    temp = s.split()
    res = ""
    for i in range(len(temp)-1, -1, -1):
        if res == "":
            res += temp[i]
        else:
            res = res + " " + temp[i]
    return res


# better version
def reverseWords(s: str) -> str:
    list_words = s.split()
    str = ""
    #" ".join 하면 중간 중간 띄어쓰기도 해줌.
    str = " ".join(list_words[::-1])
    return str

