def removeDuplicates(nums: [int]) -> int:
    nums[:] = sorted(set(nums))
    return len(nums)

def removeDuplicates2(nums):
    idx = 1
    for i in range(1, len(nums)):
        if nums[i] != nums[i-1]:
            nums[idx] = nums[i]
            idx += 1
    return idx    
