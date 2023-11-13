
def longestCommonPrefix(strs):
    prefix = strs[0]
    for i in range(1,len(strs)):
        if len(prefix) > len(strs[i]):
            prefix = strs[i]

    for i in range(len(strs)):
        while len(prefix) > 0:
            if strs[i][:len(prefix)]== prefix:
                break
            else:
                prefix = prefix[:len(prefix)-1]


    return prefix