class Solution:
    def trailingZeroes(self, n: int) -> int:
        cnt = 0
        while n!=0:
            n //= 5
            cnt += n
        return cnt