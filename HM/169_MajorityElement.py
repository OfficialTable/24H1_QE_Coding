def majorityElement(nums: [int]) -> int:
    n = len(nums)
    temp = dict()

    for i in nums:
        if i not in temp:
            temp[i] = 1
        else:
            temp[i] += 1

    for i in temp:
        if temp[i] > (n/2):
            return i