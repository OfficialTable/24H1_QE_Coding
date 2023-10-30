'''
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
'''

def majorityElement(nums: list) -> int:
    len_nums = len(nums)
    if len_nums == 1:
        return nums[0]
    else:
        nums.sort()
        return nums[len_nums//2]
    
if __name__ == "__main__":
    print("169_MajorityElement.py")
    print("\nCase 1")
    nums = [3,2,3]
    ans = 3
    res = majorityElement(nums)
    print(res, "\n==> check: ", res==ans)

    print("\nCase 2")
    nums = [2,2,1,1,1,2,2]
    ans = 2
    res = majorityElement(nums)
    print(res, "\n==> check: ", res==ans)

 
