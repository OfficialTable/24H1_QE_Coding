
# Sol1: Replace nth element with the value that is not equal to num
def removeElement(nums: List[int], val: int) -> int:
    idx = len(nums)
    count = 0
    for i in range(idx):
        if nums[i] != val:
            nums[count] = nums[i]
            count += 1
    return count

if __name__ == "__main__":
    print("027_RemoveElement.py")
    print("\nCase 1")
    nums = [3,2,2,3]
    val = 3 
    ans = 2
    res = removeElement(nums, val)
    print(res, "\n==> check: ", res==ans)
    print(nums)


    print("\nCase 2")
    nums = [0,1,2,2,3,0,4,2]
    val = 2
    ans = 5
    res = removeElement(nums, val)
    print(res, "\n==> check: ", res==ans)
    print(nums)

    print("\nCase 3")
    nums = [1]
    val = 1
    ans = 0
    res = removeElement(nums, val)
    print(res, "\n==> check: ", res==ans)
    print(nums)

    print("\nCase 4")
    nums = [4,5]
    val = 5
    ans = 1
    res = removeElement(nums, val)
    print(res, "\n==> check: ", res==ans)
    print(nums)