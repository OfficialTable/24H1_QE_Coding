
def twoSum(nums, target):
    for i in range(len(nums)):
        com = target - nums[i]
        if com in nums[i+1:]:
            return [i, nums[i+1:].index(com) + (i+1)]

    return        