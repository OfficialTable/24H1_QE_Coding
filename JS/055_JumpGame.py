'''
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
'''


def canJump(nums: list) -> bool:
    last_idx_possible = 0
    for i, n in enumerate(nums):
#        print(i,n,last_idx_possible)
        if i > last_idx_possible:
            return False
        last_idx_possible = max(last_idx_possible, i+n)

    return True

if __name__ == "__main__":
    print("055_JumpGame.py")
    print("\nCase 1")
    nums = [2,3,1,1,4]
    ans = True
    res = canJump(nums)
    print(res, "\n==> check: ", res==ans)


    print("\nCase 2")
    nums = [3,2,1,0,4]
    res = canJump(nums)
    ans = False
    print(res, "\n==> check: ", res==ans)
