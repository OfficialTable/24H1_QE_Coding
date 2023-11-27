def lengthOfLongestSubstring(s: str) -> int:
    slidingWindow = set()
    left = 0
    res = 0

    for right in range(len(s)):
        #오른쪽 포인터가 지금 슬라이딩 윈도우에 있을 경우 *왼포인터랑겹칠때
        while s[right] in slidingWindow:
            #왼 포인터를 슬라이딩 윈도우에서 삭제
            slidingWindow.remove(s[left])
            #왼 포인터를 한칸 옮김
            left += 1
        #그렇지 않으면, 슬라이딩 윈도우에 추가
        slidingWindow.add(s[right])
        #현재 슬라이딩 윈도우 길이가 더 길다면 res값을 업데이트
        res = max(res, len(slidingWindow))

    return res