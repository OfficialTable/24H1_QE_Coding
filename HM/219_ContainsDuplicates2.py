##그냥 조건문걸면 TLE에러뜸.
def containsNearbyDuplicate(nums: [int], k: int) -> bool:
    d = dict()
    for i in range(len(nums)):
        if nums[i] in d:
            if abs(d[nums[i]] - i) <= k:
                return True
        d[nums[i]] = i
    return False