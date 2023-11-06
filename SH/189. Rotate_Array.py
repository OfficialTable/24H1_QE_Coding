def rotate(nums:List[int], k: int)->None:
    n = len(nums)
    k = k%n
    nums[:] = nums[n-k:]+nums[:n-k]
    return nums