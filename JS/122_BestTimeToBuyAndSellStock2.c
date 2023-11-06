#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int accum_profit = 0;
    for (int i; i<pricesSize-1; i++) {
        if (prices[i+1] > prices[i]) {
            accum_profit += prices[i+1] - prices[i];
        }
    }
    return accum_profit;
}

// Driver code
int main(void) {
    printf("Case 1:\n");
    int nums1[6] = {7,1,5,3,6,4};
    int nums1Size = 6;
    int res1 = maxProfit(nums1, nums1Size);
    printf("%d\n", res1);
    printf("\n");

    printf("Case 2:\n");
    int nums2[5] = {7,6,4,3,1};
    int nums2Size = 5;
    int res2 = maxProfit(nums2, nums2Size);
    printf("%d\n", res2);
    printf("\n");

    printf("Case 3:\n");
    int nums3[5] = {1,2,3,4,5};
    int nums3Size = 5;
    int res3 = maxProfit(nums3, nums3Size);
    printf("%d\n", res3);
    printf("\n");
}
