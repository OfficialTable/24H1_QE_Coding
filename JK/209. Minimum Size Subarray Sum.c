#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int min_len = INT_MAX;  
    int left = 0;  
    int current_sum = 0; 

    for (int right = 0; right < numsSize; right++) {
        current_sum += nums[right];

        while (current_sum >= target) {
            min_len = min_len < (right - left + 1) ? min_len : (right - left + 1);  
            current_sum -= nums[left];  
            left++;
        }
    }

    return min_len != INT_MAX ? min_len : 0;
}

int main() {
    int nums[] = {2, 3, 1, 2, 4, 3};
    int target = 7;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = minSubArrayLen(target, nums, numsSize);
    printf("%d\n", result);  // 결과 출력
    return 0;
}
