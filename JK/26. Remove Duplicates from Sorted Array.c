#include <stdio.h>


int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}


int main() {
    int nums[] = {1, 1, 2, 3, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    numsSize = removeDuplicates(nums, numsSize);

    printf("Array without duplicates: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNew array size: %d\n", numsSize);

    return 0;
}