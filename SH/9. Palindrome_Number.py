# using String
class Solution:
    def isPalindrome(self, x: int) -> bool:
        str_num = str(x)
        n = len(str_num)
        if(n%2): # if x has odd size
            if str_num[0:n//2] == str_num[n:n//2:-1]:
                return True
        else:
            if str_num[0:n//2] == str_num[n:n//2-1:-1]:
                return True
        return False
    
# using structure of integer
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x != 0 and x % 10 == 0):
            return False

        reversed_num = 0
        original = x

        while x > reversed_num:
            reversed_num = reversed_num * 10 + x % 10
            x //= 10

        return x == reversed_num or x == reversed_num // 10