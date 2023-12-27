## Q1 ##

def str_perm(string):
    temp = []

    if len(string) == 1:
        return [string]
    else:
        for char in string:
            # print("char:", char)
            # replace the first occurance of the char to empty string
            for a in str_perm(string.replace(char, "", 1)):
                # print("a:", a)
                # print("char + a:", char + a)
                temp.append(char + a)
                # print(temp)  
    ans = set(temp)
    
    return sorted(ans)


# Driver Code
if __name__ == '__main__':
    test1 = "abc"
    test2 = "abb"

    print(str_perm(test1))
    print(str_perm(test2))
