'''
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
'''


def jump(nums: list) -> int:
    cnt, end, farthest = 0, 0, 0
    size_nums = len(nums)

    # Loop through the nums except the last one
    for i in range(size_nums-1):
        farthest = max(farthest, i+nums[i])

        if farthest >= size_nums-1:
            cnt += 1
            return cnt

        if i == end:
            cnt += 1
            end = farthest
        
    return cnt

if __name__ == "__main__":
    print("045_JumpGame2.py")
    print("\nCase 1")
    nums = [2,3,1,1,4]
    ans = 2
    res = jump(nums)
    print(res, "\n==> check: ", res==ans)


    print("\nCase 2")
    nums = [2,3,0,1,4]
    ans = 2
    res = jump(nums)
    print(res, "\n==> check: ", res==ans)
