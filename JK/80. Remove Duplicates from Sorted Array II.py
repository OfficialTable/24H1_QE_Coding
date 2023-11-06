def removeDuplicates(nums):
    index = 1  
    count = 1  

    for i in range(1, len(nums)):
        if nums[i] == nums[i - 1]:
            count += 1
        else:
            count = 1
        
        if count <= 2:
            nums[index] = nums[i]
            index += 1               

    return index  


# nums = [1,1,1,2,2,3]
# removeDuplicates(nums)