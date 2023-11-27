def lengthOfLongestSubstring(s: str) -> int:
    charIndexMap = {}
    maxLength = 0
    start = 0

    for i, char in enumerate(s):
        if char in charIndexMap and charIndexMap[char] >= start:
            start = charIndexMap[char] + 1
        charIndexMap[char] = i
        maxLength = max(maxLength, i - start + 1)

    return maxLength    