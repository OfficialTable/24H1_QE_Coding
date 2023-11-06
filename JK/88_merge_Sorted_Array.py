def merge(nums1, m, nums2, n) -> None:
    for l in range(len(nums1), m, -1):
        nums1.pop()
    for l in range(len(nums2), n, -1):
        nums2.pop()        
    
    
    nums1.extend(nums2)
    nums1.sort()


# nums1 = [1,2,3,0,0,0]
# m = 3
# nums2 = [2,5,6]
# n = 3
# merge(nums1, m, nums2, n)