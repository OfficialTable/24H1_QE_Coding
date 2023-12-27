## Q1 ##

### (a)
def palindrome(s: str) -> bool:
    flag = False
    if s == s[::-1]:
        flag = True
    return flag

### (b)
def substring(s: str, t: str) -> bool:
    flag = False
    if t in s:
        flag = True
    return flag

### (c)
def max_palindromes(s: str) -> list:

    #0. set parameters
    s_length = len(s)
    pal_list = []
    max_pals_list = []

    #1. find the distinct palindrome-substrings
    for i in range(s_length):
        for j in range(i+1, s_length+1):
            target = s[i:j]
            # print(f"({i}, {j}): {target}")            
            if (palindrome(target)) and (target not in pal_list):
                pal_list.append(target)

    #2. make max_palindrome list
    for i in pal_list:
        #2-1. set flag
        max_flag = True

        #2-2. check whether i is not same with j, but substring of j --> max_flag = False
        for j in pal_list:
            '''
            i: target string
            j: comparing string
            '''
            if i != j and substring(j, i):
                max_flag = False
                break
        
        #2-3. add if max_flag == True
        if max_flag:
            max_pals_list.append(i)

    return max_pals_list


# Driver Code
if __name__ == '__main__':
    testa1 = "asdsa"
    testa2 = "asddsa"
    testa3 = "asefavsae"

    testc1 = "kabccbadzdefgfeda"
    testc2 = "kabccba dzabccbaza"
    testc3 = "bbacaz"

    sub1 = 'a'
    sub2 = 'f'

    # (a) palindrome test
    print("\n(a) test")
    print(palindrome(testa1)) #True
    print(palindrome(testa2)) #True
    print(palindrome(testa3)) #False

    # (b) substring test
    print("\n(b) test")
    print(substring(testc1, sub1)) #True
    print(substring(testc2, sub1)) #True
    print(substring(testc1, sub2)) #True
    print(substring(testc2, sub2)) #False

    # (c) max_palindrome test
    print("\n(c) test")
    print(max_palindromes(testc1))
    print(max_palindromes(testc2))
    print(max_palindromes(testc3))
