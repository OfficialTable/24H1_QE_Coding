#include <stdio.h>

// Function to reverse a segment of an array from index start to end
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

// Function to rotate the array to the right by k steps
void rotate(int* nums, int numsSize, int k) {
    // Ensure k is not greater than the size of the array
    k %= numsSize;

    // Reverse the entire array
    reverse(nums, 0, numsSize - 1);
    // Reverse the first k elements
    reverse(nums, 0, k - 1);
    // Reverse the remaining n-k elements
    reverse(nums, k, numsSize - 1);
}


int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3; // Rotate the array to the right by 3 steps

    rotate(nums, numsSize, k);

    // Print the rotated array
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}


// 시간초과
// #include <stdio.h>

// void rotate(int* nums, int numsSize, int k) {
//     k = k % numsSize; 
//     int temp;

//     for (int i = 0; i < k; i++) {
//         temp = nums[numsSize - 1];

//         for (int j = numsSize - 1; j > 0; j--) {
//             nums[j] = nums[j - 1];
//         }

//         nums[0] = temp;
//     }
// }