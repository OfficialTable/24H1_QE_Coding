/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int start, end;
    int *answer = (int *)malloc(sizeof(int)*2);
    start, end = 0, (numbersSize--);
    while(start<end){
        int sum = numbers[start] + numbers[end];
        if(sum==target){break;}
        if(sum>target){end--;}
        else{start++;}
    }
    answer[0] = start+1; 
    answer[1] = end+1;
    return answer;  
}

