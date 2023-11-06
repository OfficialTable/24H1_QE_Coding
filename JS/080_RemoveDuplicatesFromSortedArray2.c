#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    // edge case
    if (numsSize <= 2) {
        return numsSize;
    }
    // general case
    int idx = 2;
    int res[numsSize];
    res[0] = nums[0];
    res[1] = nums[1];
    for (int i=2; i<numsSize; i++) {
        if (nums[i] != nums[idx-2]) {
            res[idx] = nums[i];
            idx++;
        }
    }
    for (int i=0; i<idx; i++) {
        nums[i] = res[i];
    }
    return idx;
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    int numsSize1 = 6;
    int nums1[6] = {1,1,1,2,2,3};
    int res1 = removeDuplicates(nums1, numsSize1);
    printf("%d\n", res1);
    for (int i=0; i<res1; i++) {
        if (i==0) {
            printf("[%d, ", nums1[i]);
        }
        else if (i < res1-1){
            printf("%d, ", nums1[i]);
        }
        else {
            printf("%d]", nums1[i]);
        }
    }
    printf("\n");

    printf("Case 2:\n");
    int numsSize2 = 9;
    int nums2[9] = {0,0,1,1,1,1,2,3,3};
    int res2 = removeDuplicates(nums2, numsSize2);
    printf("%d\n", res2);
    for (int i=0; i<res2; i++) {
        if (i==0) {
            printf("[%d, ", nums2[i]);
        }
        else if (i < res2-1){
            printf("%d, ", nums2[i]);
        }
        else {
            printf("%d]", nums2[i]);
        }
    }
    printf("\n");

}