void rotate(int* nums, int numsSize, int k) {
    while (k > numsSize) {
        k = k - numsSize;
    }
    int n = numsSize - k;

    if (k != 0) {
        // Temporary array to store the rotated elements
        int temp[numsSize];

        // Copy the elements to be rotated to the temporary array
        for (int i = 0; i < k; i++) {
            temp[i] = nums[n + i];
        }

        // Shift the remaining elements to the right
        for (int i = 0; i < n; i++) {
            temp[k + i] = nums[i];
        }

        // Copy the rotated elements back to the original array
        for (int i = 0; i < numsSize; i++) {
            nums[i] = temp[i];
        }
    }
}
