int removeDuplicates(int* nums, int numsSize) {
    int count = 1;
    for(int i=0; i<numsSize; i++){
        if(nums[i]!=nums[count-1]){
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}




