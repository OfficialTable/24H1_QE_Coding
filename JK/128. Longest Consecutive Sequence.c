#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    qsort(nums, numsSize, sizeof(int), compare);

    int ans = 1, output = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] + 1 == nums[i + 1]) {
            output++;
        } else if (nums[i] != nums[i + 1]) {
            if (ans < output) {
                ans = output;
            }
            output = 1;
        }
    }

    return (ans < output) ? output : ans;
}