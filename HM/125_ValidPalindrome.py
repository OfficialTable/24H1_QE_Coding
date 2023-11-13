def isPalindrome(s:str) -> bool:
    lower = str.lower(s)
    new = ""
    for i in lower:
        if str.isalnum(i):
            new += i
    return new == new[::-1]
