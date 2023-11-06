#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0; 
    int k = 0; 
    
    while (i < numsSize) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
        i++;
    }
    
    return k;
}


int main() {
    int nums[] = {3, 2, 2, 3};
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    numsSize = removeElement(nums, numsSize, val);

    printf("Array after removing %d: \n", val);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNew array size: %d\n", numsSize);

    return 0;
}