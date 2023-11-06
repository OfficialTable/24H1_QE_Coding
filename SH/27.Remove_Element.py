
# Sol1: Replace nth element with the value that is not equal to num
def removeElement(nums: List[int], val: int) -> int:
    idx = len(nums)
    count = 0
    for i in range(idx):
        if nums[i] != val:
            nums[count] = nums[i]
            count += 1
    return count