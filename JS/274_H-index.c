#include <stdio.h>
#include <stdbool.h>

int hIndex(int* citations, int citationsSize){
    int h_idx_cnt[citationsSize+1];
    int h_idx = 0;

    for (int i=0; i<citationsSize+1; i++){
        h_idx_cnt[i] = 0;
    }

    for (int i=0; i<citationsSize; i++){
        if (citations[i] >= citationsSize){
            h_idx_cnt[citationsSize] ++;
        } else {
            h_idx_cnt[citations[i]] ++;
        }
    }

    for (int i=citationsSize; i>=0; i--){
        h_idx += h_idx_cnt[i];
        if (h_idx >= i){
            return i;
        }
    }
    return h_idx;
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    
    int numsSize1 = 5;
    int nums1[5] = {2,3,1,1,4};
    int res1 = hIndex(nums1, numsSize1);
    printf("%d\n", res1);

    printf("Case 2:\n");
    int numsSize2 = 5;
    int nums2[5] = {2,3,0,1,4};
    int res2 = hIndex(nums2, numsSize2);
    printf("%d\n", res2);

}
