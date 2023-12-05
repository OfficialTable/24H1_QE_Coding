def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(len(nums)):
                if nums[i] + nums[j] == target and i != j:
                    return [i, j]
                
###dict 방식으로 (Contains Duplicates2처럼 풀기)
def twoSum(self, nums: List[int], target: int) -> List[int]:
    d = dict()
    for i in range(len(nums)):
        diff = target - nums[i]
        if diff in d:
            return [d[diff], i]
        d[nums[i]] = i
