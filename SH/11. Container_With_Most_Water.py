def maxArea(height: List[int]) -> int:
    area = 0
    start, end = 0, len(height)-1
    while(start<end):
        tmp_b = end-start
        tmp_h = min(height[start], height[end])
        tmp_a = tmp_b * tmp_h
        area = max(area, tmp_a)
        if height[start] < height[end]:
            start += 1
        else:
            end -= 1
    return area