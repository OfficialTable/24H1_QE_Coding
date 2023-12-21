class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp=defaultdict(list)
        bl=defaultdict(bool)
        mx=0
        for i in nums:
            if bl[i]:
                continue 
            bl[i]=True
            l,r=i,i
            if mp[i+1]:
                r=mp[i+1][0]
            if mp[i-1]:
                l=mp[i-1][1]
            mp[r]=[r,l]
            mp[l]=[r,l]
            mx=max(mx,r-l+1)
        return mx