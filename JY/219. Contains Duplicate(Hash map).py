class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        nums_dict = {}

        for i in range(len(nums)):
            if nums[i] not in nums_dict:
                nums_dict[nums[i]] = [i]
            else :
                nums_dict[nums[i]].append(i)

        for indexes in nums_dict.values():
            if len(indexes) >= 2:
                for j in range(len(indexes)-1): #1~len(indexes) 또는 len(indexes)-1
                   if indexes[j+1] - indexes[j] <= k: 
                        return True
        return False