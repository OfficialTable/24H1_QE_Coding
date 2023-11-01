int removeElement(int* nums, int numsSize, int val){
    int new_idx = 0;
    // i <= numsSize는 안된다, index는 0부터 시작하니까 사실상 끝이 numsSize-1인것.
    for(int i = 0; i < numsSize; i++){
        if (nums[i] != val){
            nums[new_idx] = nums[i];
            new_idx++;
        }
    }
    return new_idx;
}