int minSubArrayLen(int target, int* nums, int numsSize) {
    int current_sum = 0;
    int min_length = 1000000;
    int start = 0;

    for (int i = 0 ; i < numsSize ; i++){
        current_sum += nums[i];
        while (current_sum >= target){
            min_length = (min_length < (i - start +1)) ? min_length : (i - start +1);            
            current_sum -= nums[start];
            start++;

        }
            
    }
    int result = (min_length==1000000) ? 0 : min_length ;
    return result;
}