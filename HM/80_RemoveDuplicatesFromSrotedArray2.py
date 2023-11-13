def removeDuplicates(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    idx = 0

    for i in nums:
        if idx < 2 or i != nums[idx-2]:
            nums[idx] = i
            idx += 1
    return idx