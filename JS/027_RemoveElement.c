#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int cnt_dup = 0;
    for(int i=0; i<numsSize; i++) {
        if(nums[i] == val) {
            cnt_dup++;
        } else {
            nums[i-cnt_dup] = nums[i];
        }
    }
    return (numsSize - cnt_dup);
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    
    int numsSize1 = 4;
    int nums1[4] = {3,2,2,3};
    int val1 = 3;
    int res1 = removeElement(nums1, numsSize1, val1);
    printf("%d\n", res1);

    printf("Case 2:\n");
    int numsSize2 = 8;
    int nums2[8] = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int res2 = removeElement(nums2, numsSize2, val2);
    printf("%d\n", res2);

}
