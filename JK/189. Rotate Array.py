def rotate(nums, k):
    """
    Do not return anything, modify nums in-place instead.
    """
    for i in range(k):
        val = nums.pop()
        nums.insert(0,val)

# nums = [1,2,3,4,5,6,7]
# k = 3
# rotate(nums, k)
# nums