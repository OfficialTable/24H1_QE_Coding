def removeElement(nums, val):
    while val in nums:    
        nums.remove(val)

    return len(nums)

# nums = [3,2,2,3]
# val = 3
# removeElement(nums, val)