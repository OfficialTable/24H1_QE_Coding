#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize){
    int last_idx_possible = 0;
    for (int i=0; i<numsSize; i++){
        if (i>last_idx_possible){
            return false;
        }
        
        if (i+nums[i] > last_idx_possible){
            last_idx_possible = i+nums[i];
        }
    }
    return true;
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    
    int numsSize1 = 5;
    int nums1[5] = {2,3,1,1,4};
    bool res1 = canJump(nums1, numsSize1);
    printf("%d\n", res1);

    printf("Case 2:\n");
    int numsSize2 = 5;
    int nums2[5] = {3,2,1,0,4};
    bool res2 = canJump(nums2, numsSize2);
    printf("%d\n", res2);

}
