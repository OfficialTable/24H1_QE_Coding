def reverseWords(s: str) -> str:
    list_words = s.split()
    str = ""
    str = " ".join(list_words[::-1])
    return str
