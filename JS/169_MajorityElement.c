#include <stdio.h>

void swap(int* xp, int* yp);
void selectionSort(int arr[], int n);

int majorityElement(int* nums, int numsSize){
    selectionSort(nums, numsSize);
    return nums[numsSize/2];
}


void swap(int* xp, int* yp) { 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// Function to perform Selection Sort 
void selectionSort(int arr[], int n) { 
    int i, j, min_idx; 
  
    // One by one move boundary of 
    // unsorted subarray 
    for (i = 0; i < n - 1; i++) { 
        // Find the minimum element in 
        // unsorted array 
        min_idx = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
  
        // Swap the found minimum element 
        // with the first element 
        swap(&arr[min_idx], &arr[i]); 
    } 
} 

// Driver code
int main(void) {
    printf("Case 1:\n");
    int numsSize1 = 3;
    int nums1[3] = {3,2,3};
    int res1 = majorityElement(nums1, numsSize1);
    printf("%d\n", res1);

    printf("Case 2:\n");
    int numsSize2 = 7;
    int nums2[7] = {2,2,1,1,1,2,2};
    int res2 = majorityElement(nums2, numsSize2);
    printf("%d\n", res2);

}
