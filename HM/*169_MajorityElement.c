int majorityElement(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return -1;  // No majority element in an empty array
    }

    int maxNum = nums[0];
    int count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (count == 0) {
            maxNum = nums[i];
            count = 1;
        } else if (nums[i] == maxNum) {
            count++;
        } else {
            count--;
        }
    }

    // Verify if the found element is a majority element
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == maxNum) {
            count++;
        }
    }

    return (count > numsSize / 2) ? maxNum : -1;
}