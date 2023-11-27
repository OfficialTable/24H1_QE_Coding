int minSubArrayLen(int target, int* nums, int numsSize) {
    int c = INT_MAX, start = 0, tail = 0, sum = 0;

    while(start < numsSize)
    {
        sum += nums[start];
        while(sum >= target)
        {
            c = fmin(c, (start-tail+1));
            sum -= nums[tail];
            tail++;
        }
        start++;
    }
    if(c != INT_MAX)
    {
        return c;
    }
    else
    {
        return 0;
    }
}