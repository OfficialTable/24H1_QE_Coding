class Solution:
    def kthPalindrome(self, queries: List[int], intLength: int) -> List[int]:
        res=[]
        ln=ceil(intLength/2)
        odd=intLength%2==1
        base=10**(ln-1)
        def getLalindrome(k:int)->int:
            val=str(k-1+base)
            if len(val)>ln:
                return -1
            return int(val+val[-2::-1]) if odd else int(val+val[::-1])
        for q in queries:
            res.append(getLalindrome(q))  
        return res

# Can't get some edge cases
def palindorme(s:str)->bool:
    idx = len(s)
    if(idx%2): # odd number
        if s[0:idx//2] == s[idx:idx//2:-1]:
            return True
    else:
        if s[0:idx//2] == s[idx:idx//2-1:-1]:
            return True
    return False

def kthPalindrome(queries: List[int], intLength: int) -> List[int]:
    start = 10**(intLength-1)
    end = 10**(intLength)
    palindromes = [-1] * (len(queries))
    count = 0
    for i in range(start, end):
        if palindorme(str(i)):
            count += 1
            if ((count) in queries):
                #idx = queries.index(count)
                idx = [n for n, x in enumerate(queries) if x == count]
                for j in idx:
                    palindromes[j] = i
    return palindromes