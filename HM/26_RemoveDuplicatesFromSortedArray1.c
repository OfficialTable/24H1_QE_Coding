int removeDuplicates(int* nums, int numsSize){
    int idx = 1;
    for (int i=1; i < numsSize; i++){
        if (nums[i] != nums[i-1]){
            nums[idx] = nums[i];
            idx++;
        }
    }
    return idx;
}