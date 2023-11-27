
def isPalindrome(s: str) -> bool:

    answer = ''.join(c.lower() for c in s if c.isalnum())
    
    return answer == answer[::-1]        