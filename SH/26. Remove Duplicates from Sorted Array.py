def removeDuplicates(nums: List[int])->int:
    memo = []
    idx = len(nums)
    count = 0
    for i in range(idx):
        if nums[i] not in memo:
            nums[count] = nums[i]
            memo.append(nums[i])
            count += 1
    return count



if __name__ == "__main__":
    print("26. Remove Duplicates from Sorted Array")
    print("\nCase 1")
    s = [1,1,2]
    ans = 2
    res = removeDuplicates(s)
    print(res, "\n==> check: ", res==ans)

