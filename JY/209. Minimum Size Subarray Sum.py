class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0

        start = 0
        current_sum = 0
        min_length = 1000000

        for end in range(len(nums)):
            current_sum +=nums[end]

            while current_sum >= target:
                min_length = min(end-start+1, min_length)
                current_sum -= nums[start]
                start += 1

        return min_length if min_length != 1000000 else 0