# Soln1: Compare from the end of the array
def merge(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    for i in range(m, m+n):
        nums1[i] = nums2[i-m]
    nums1.sort()
    return nums1
            

# Soln2: Put all elements of nums1 and nums2 into nums1 then sort it
def merge(nums1: List[int], m: int, nums2: List[int], n: int) -> None:
    a, b, idx = m-1, n-1, m+n-1 # -1 for index of array
    
    while b >= 0:
        if a >= 0 and nums1[a] > nums2[b]:
            nums1[idx] = nums1[a]
            a -= 1
        else:
            nums1[idx] = nums2[b]
            b -= 1
        idx -= 1
    return nums1

