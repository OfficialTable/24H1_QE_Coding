#include <stdio.h>

void rotate(int* nums, int numsSize, int k){
    int res[numsSize];
    for (int i=0; i<k; i++){
        res[i] = nums[numsSize-k+i];
    }
    for (int i=k; i<numsSize; i++){
        res[i] = nums[i-k];
    }
    // copy
    for (int i=0; i<numsSize; i++) {
        nums[i] = res[i];
    }
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    int nums1[7] = {1,2,3,4,5,6,7};
    int nums1Size = 7;
    rotate(nums1, nums1Size, 3);
    for (int i=0; i<nums1Size; i++) {
        if (i==0) {
            printf("[%d, ", nums1[i]);
        }
        else if (i < nums1Size-1){
            printf("%d, ", nums1[i]);
        }
        else {
            printf("%d]", nums1[i]);
        }
    }
    printf("\n");

    printf("Case 2:\n");
    int nums2[4] = {-1,-100,3,99};
    int nums2Size = 4;
    rotate(nums2, nums2Size, 2);
    for (int i=0; i<nums2Size; i++) {
        if (i==0) {
            printf("[%d, ", nums2[i]);
        }
        else if (i < nums2Size-1){
            printf("%d, ", nums2[i]);
        }
        else {
            printf("%d]", nums2[i]);
        }
    }
    printf("\n");
}
