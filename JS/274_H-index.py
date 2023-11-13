'''
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward hIndex from index i. In other words, if you are at nums[i], you can hIndex to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of hIndexs to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of hIndexs to reach the last index is 2. hIndex 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
'''


def hIndex(citations: list) -> int:
    num_papers = len(citations)
    h_idx_cnt = [0 for _ in range(num_papers+1)]
    h_idx = 0
    # Count papers of which cited count is the idx of h_idx_cnt
    for c in citations:
        if c > num_papers:
            h_idx_cnt[num_papers] += 1
        else:
            h_idx_cnt[c] += 1

    # Go backward the first index such that the count >= current inde
    for i in range(num_papers, -1, -1):
        h_idx += h_idx_cnt[i]
        if h_idx >= i:
            return i

    return h_idx

if __name__ == "__main__":
    print("274_H-index.py")
    print("\nCase 1")
    nums = [2,3,1,1,4]
    ans = 2
    res = hIndex(nums)
    print(res, "\n==> check: ", res==ans)


    print("\nCase 2")
    nums = [2,3,0,1,4]
    ans = 2
    res = hIndex(nums)
    print(res, "\n==> check: ", res==ans)
