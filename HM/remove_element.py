def removeElement(nums, val):
    """
    :type nums: List[int]
    :type val: int
    :rtype: int
    """
    new_idx = 0
    for i in range(len(nums)):
        if nums[i] != val:
            nums[new_idx] = nums[i]
            new_idx += 1

    return new_idx