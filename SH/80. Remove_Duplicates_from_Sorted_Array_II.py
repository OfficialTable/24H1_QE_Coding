def removeDuplicates(nums: List[int])->int:
    memo = {}
    idx = len(nums)
    count = 0
    for i in range(idx):
        if nums[i] not in memo: # Dictionary key should be the number
            nums[count] = nums[i]
            memo[nums[i]] = 1
            count += 1
        elif memo[nums[i]] == 1:
            nums[count] = nums[i]
            memo[nums[i]] = 2
            count += 1
    return count