#include <stdio.h>
#include <stdbool.h>

int Jump(int* nums, int numsSize){
    int cnt=0, end=0, farthest=0;

    for (int i=0; i<numsSize-1; i++){
        // printf("%d, %d, %d: i, cnt, end \n", i, cnt, end);
        // printf("%d: farthest\n", farthest);
        // printf("%d: i+num[i]\n", i+nums[i]);
        if(farthest < i+nums[i]){
            farthest = i+nums[i];
        }

        if (farthest >= numsSize-1){
            cnt ++;
            return cnt;
        }

        if (i == end){
            cnt++;
            end = farthest;
        }
    }
    return cnt;
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    
    int numsSize1 = 5;
    int nums1[5] = {2,3,1,1,4};
    int res1 = Jump(nums1, numsSize1);
    printf("%d\n", res1);

    printf("Case 2:\n");
    int numsSize2 = 5;
    int nums2[5] = {2,3,0,1,4};
    int res2 = Jump(nums2, numsSize2);
    printf("%d\n", res2);

}
