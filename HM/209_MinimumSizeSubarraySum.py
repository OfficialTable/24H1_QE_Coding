def minSubArrayLen(target: int, nums: List[int]) -> int:
    left, total = 0, 0
    res = len(nums) + 1 #any invalid values e.g. float("inf")
    #sliding window
    for right in range(len(nums)):
        #total에 right value를 하나씩 넣으면서
        total += nums[right]
        #만약 이것이 target보다 커지면
        while total >= target:
            #현재 sliding window크기 혹은, 이전것이 작다면 그것을 업데이트
            res = min(right - left + 1, res) 
            #다음 슬라이딩으로 넘어가기 위해 left value를 하나 빼주고
            total -= nums[left]
            #다음칸으로 left 이동
            left += 1
    #초기 설정한 말도안되는 res값이라면 (한번도 업데이트 안된것 조건문 충족 X) 0, else 결과값
    return 0 if res == len(nums) + 1 else res