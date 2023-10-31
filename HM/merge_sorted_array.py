def merge(nums1:[int], m: int, nums2:[int], n: int) -> None:
    """
    Do not return anything, modify nums1 in-place instead.
    """
    i, j, k = m-1, n-1, m+n-1

    #nums2가 []이 아닐 때
    while j >= 0:
        #nums1도 []이 아니고 nums1의 마지막 원소가 nums2의 마지막 원소보다 크면
        if i >= 0 and nums1[i] > nums2[j]:
            #nums1의 마지막 원소를 통합 마지막 원소로
            nums1[k] = nums1[i]
            i -= 1
        else:
            #반대면 nums2의 마지막 원소를 통합 마지막 원소로
            nums1[k] = nums2[j]
            j -= 1

        k -=1
