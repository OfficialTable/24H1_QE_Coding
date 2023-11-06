def isPalindrome(s: str) -> bool:
    arr = []
    # Put the letters in the list
    for letter in s:
        if letter.isalpha() or letter.isnumeric():
            arr.append(letter.lower())
    
    idx_length = len(arr) # 21
    if (idx_length%2): # if idx_length is odd
        if (arr[0:idx_length//2] == arr[idx_length:idx_length//2:-1]):
            return True
    else:
        if (arr[0:idx_length//2] == arr[idx_length:idx_length//2-1:-1]):
            return True
    return False    

if __name__ == "__main__":
    print("125_Valid_Palindrome.py")
    print("\nCase 1")
    s = "A man, a plan, a canal: Panama"
    ans = True
    res = isPalindrome(s)
    print(res, "\n==> check: ", res==ans)


    
        