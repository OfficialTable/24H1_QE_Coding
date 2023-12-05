int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

int *array = malloc(2 * sizeof(int));
*returnSize = 2;

    for (int i = 0; i < numsSize; i++){
        for (int j = 0; j <numsSize; j++){
            if (nums[i] + nums[j] == target && i != j){
                array[0] = i;
                array[1] = j;
                return array;
            }
        }
    }
    return -1;
}
