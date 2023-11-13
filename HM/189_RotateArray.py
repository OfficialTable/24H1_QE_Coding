def rotate(nums: [int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    while k > len(nums):
        k = k - len(nums)
    n = len(nums) - k
    if k != 0:
        nums[:] = nums[n:] + nums[:-k]
    
    #return nums