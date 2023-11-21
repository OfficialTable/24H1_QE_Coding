'''
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.
'''

def print_cache(cache):
    for row in cache:
        print(row)
    print("\n")

def longestPalindromeSubseq(s:str) -> int:
    length = len(s)
    cache = [[0 for _ in range(length)] for _ in range(length)]
    print_cache(cache)
    for back in range(1, length+1):
        idx_range = length - back + 1
        for row in range(idx_range):
            col = row + back - 1
            print(f"row,col = ({row}, {col})")
            print(f"string: {s[row:col+1]}")

            # single char -> palindrome of length 1
            if row == col: 
                cache[row][col] = 1
                print("single char")

            # two chars & the chars are same-> palindrome of length 2
            elif row + 1 == col and s[row] == s[col]:
                cache[row][col] = 2
                print("two chars")

            # more than two chars & the chars are same -> palindrome of length 2 + palindrome of length 2
            elif s[row] == s[col]:
                cache[row][col] = cache[row+1][col-1] + 2
                print("more than two chars")

            # more than two chars & the chars are different -> max(palindrome of length 1, palindrome of length 2)
            else:
                cache[row][col] = max(cache[row+1][col], cache[row][col-1])
                print("more than two chars & the chars are different")
            print_cache(cache)

    return cache[0][-1]





if __name__ == "__main__":

    print("516_LongestPalindromicSubsequence.py")
    print("\nCase 1")
    s = "bbbab"
    res = longestPalindromeSubseq(s)
    ans = 4
    print(s)
    print(res, "\n==> check: ", res==ans)


    # print("\nCase 2")
    # s = "cbbd"
    # res = longestPalindromeSubseq(s)
    # ans = 2
    # print(s)
    # print(res, "\n==> check: ", res==ans)

