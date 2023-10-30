#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    int res[numsSize];
    int cnt_uniq = 0;
    if (numsSize == 0) {
        return 0;
    }
    else {
        res[0] = nums[0];
        cnt_uniq++;
    }
    for (int i=0; i < numsSize-1; i++) {
        if (nums[i] != nums[i+1]) {
            res[cnt_uniq] = nums[i+1];
            cnt_uniq++;
        }
    }
    for (int i=0; i<cnt_uniq; i++) {
        nums[i] = res[i];
    }
    return cnt_uniq;
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    int numsSize1 = 3;
    int nums1[3] = {1,1,2};
    int res1 = removeDuplicates(nums1, numsSize1);
    printf("%d\n", res1);
    for (int i=0; i<res1; i++) {
        if (i==0) {
            printf("[%d ,", nums1[i]);
        }
        else if (i < res1-1){
            printf("%d ,", nums1[i]);
        }
        else {
            printf("%d]", nums1[i]);
        }
    }
    printf("\n");

    printf("Case 2:\n");
    int numsSize2 = 10;
    int nums2[10] = {0,0,1,1,1,2,2,3,3,4};
    int res2 = removeDuplicates(nums2, numsSize2);
    printf("%d\n", res2);
    for (int i=0; i<res2; i++) {
        if (i==0) {
            printf("[%d ,", nums2[i]);
        }
        else if (i < res2-1){
            printf("%d ,", nums2[i]);
        }
        else {
            printf("%d]", nums2[i]);
        }
    }
    printf("\n");

}