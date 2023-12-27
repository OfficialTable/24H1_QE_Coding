class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_dict = {} #key가 num이고 value가 index

        for i, num in enumerate(nums):
            complement = target -num

            if complement in num_dict :
                return [num_dict[complement], i]
            
            num_dict[num] = i

        # output = [] # 시간 거의ㅣ 1000배 차이남
        # for i in range(len(nums)):
        #     for j in range(1, len(nums)):
        #         if i == j:
        #             break;
        #         if nums[i] + nums[j] == target:
        #             output.append(i)
        #             output.append(j)
        #             return output