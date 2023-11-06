def majorityElement(nums):
    ans = {}
    for i in range(len(nums)):
        if nums[i] in ans:
            ans[nums[i]] += 1
        else:
            ans[nums[i]] = 1

    max_ans = max(ans, key=ans.get)

    return max_ans

# nums = [3,2,3]
# majorityElement(nums)