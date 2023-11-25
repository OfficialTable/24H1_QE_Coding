# One pointer
def minSubArrayLen(target: int, nums: List[int])->int:
    left = 0
    num_sum = 0
    length = 10000000

    for i in range(len(nums)):
        num_sum += nums[i]
        while num_sum >= target:
            length = min(length, (i-left+1))
            num_sum -= nums[left]
            left += 1

    return 0 if length == 10000000 else length

# Two pointer
def minSubArrayLen(target: int, nums: List[int])->int:
    right, left = 0, 0
    num_sum = nums[right] # first element
    length = 10000000 #minimum length

    while (right<=left) and (left<len(nums)):
        if nums[left] >= target:
            return 1
        if num_sum >= target:
            length = min(length, left-right+1)
            num_sum -= nums[right]
            right += 1
        else:
            left += 1
            if left<len(nums):
                num_sum += nums[left] 
            

    return 0 if length == 10000000 else length