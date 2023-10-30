#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //1 Initialize the index of nums1 and nums2
    int i = m-1;
    int j = n-1;
    //2 Loop until i and j are greater than or equal to 0
    while(i>=0 && j>=0) {
        if(nums1[i] > nums2[j]) {
            nums1[i+j+1] = nums1[i];
            i--;
        } 
        else {
            nums1[i+j+1] = nums2[j];
            j--;
        }
    }
    while(j >= 0) {
        nums1[i+j+1] = nums2[j];
        j--;
    }
}

// Driver code
int main(void) {
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for(int i=0; i<6; i++) {
        printf("%d ", nums1[i]);
    }
}
