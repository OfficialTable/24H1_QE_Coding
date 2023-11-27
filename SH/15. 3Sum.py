def threeSum(nums: List[int]) -> List[List[int]]:
    nums.sort() # To use two pointer
    answer = []
    for i in range(len(nums)-2):
        # Base cases
        if nums[i] > 0:
            break # smallest element already exceeds 0
        if i > 0 and nums[i] == nums[i-1]:
            continue
        
        start = i+1
        end = len(nums)-1
        while start<end:
            total = nums[i]+nums[start]+nums[end]
            if total < 0: # Need larger value -> increment of start index
                start += 1
            elif total > 0: # Need smaller value
                end -= 1
            else:
                triplet = [nums[i], nums[start], nums[end]]
                answer.append(triplet)
                while start < end and nums[start]==triplet[1]:
                    start += 1 # If this already exists
                while start < end and nums[end] == triplet[2]:
                    end -= 1
    return answer