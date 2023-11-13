def twoSum(numbers: List[int], target: int) -> List[int]:
        start_1, end_1 = 0, len(numbers)-1
        while(start_1<end_1):
            sum = numbers[start_1]+numbers[end_1]
            if sum == target:
                    return [start_1+1, end_1+1]
            if sum > target:
                end_1 -= 1
            if sum < target:
                start_1 += 1
        return []