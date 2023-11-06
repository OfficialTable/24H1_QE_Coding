
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2) {
        return numsSize;
    }
    
    int index = 1;  
    int count = 1;  

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            count++;
        } else {
            count = 1;
        }

        if (count <= 2) {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}



int main() {
    int nums[] = {0,0,1,1,1,1,2,3,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    int newSize = removeDuplicates(nums, numsSize);
    
    printf("Array after removing duplicates: \n");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    
    return 0;
}