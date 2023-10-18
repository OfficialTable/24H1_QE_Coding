def foo(s:str):
    length = len(s)
    res = []
    def dfs(sub, cur):
        # print(cur)
        if len(cur) == length:
            res.append(cur)
            return
        for i, c in enumerate(sub):
            new = cur
            if len(new) == 0:
                new += c
                dfs(sub[:i] + sub[i+1:], new)
            if abs(ord(c)-ord(new[-1])) > 1:
                new += c
                dfs(sub[:i] + sub[i+1:], new)
    t = ''
    t = dfs(s, t)
    if len(res) == 0:
        res = ['']
    return res[-1]

def bar(s:str):
    s = list(set(s))
    length = len(s)
    res = []
    def dfs(sub, cur):
        # print(cur)
        if len(cur) == length:
            res.append(cur)
            return
        for i, c in enumerate(sub):
            new = cur
            if len(new) == 0:
                new += c
                dfs(sub[:i] + sub[i+1:], new)
            if abs(ord(c)-ord(new[-1])) > 1:
                new += c
                dfs(sub[:i] + sub[i+1:], new)
    t = ''
    t = dfs(s, t)
    if len(res) == 0:
        res = ['']
    return res[-1]

# Driver Code
if __name__ == '__main__':

    input = ['abcde', 'abc', '', 'abccde', 'abcdcef']

    print("Q1_a")
    for i in input:
        print(f"  input: {i} | output: {foo(i)}")

    print()

    print("Q1_b")
    for i in input:
        print(f"  input: {i} | output: {bar(i)}")
