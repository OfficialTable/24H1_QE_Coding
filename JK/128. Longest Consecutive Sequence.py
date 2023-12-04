
def longestConsecutive(nums):
    nums.sort()
    output = 1
    ans = 1
    for i in range(len(nums)-1):
        if nums[i]+1 == nums[i+1]:
            output += 1
        elif nums[i] == nums[i+1]:
            continue
        else:
            if ans < output:
                ans = output
                output = 1
            else:
                output = 1

    if ans < output:
        ans = output
    elif nums == []:
        ans = 0

    return ans