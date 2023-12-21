#time complexity O(N) solution생각해봐야됨..
def longestConsecutive(nums: [int]) -> int:
    current = 1
    maximum = 1
    nums = sorted(set(nums))        
    if len(nums) == 0:
        return 0
    for i in range(1, len(nums)):
        if nums[i-1]+1 == nums[i]:
            current += 1
        #1,2,3, 5,6,7,8,9 처럼 연속하는 리스트가 두개일수도! 더 높은 것을 처리하기 위한 코드 필요
        else:
            #현재 세던거를 max에다가 저장해두고 (더 길면), curr을 1로 초기화
            maximum = max(current, maximum)
            current = 1
    #젤 긴거 리턴
    return max(current, maximum)
