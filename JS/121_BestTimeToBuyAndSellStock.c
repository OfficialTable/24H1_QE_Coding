#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int buy = 0;
    int sell = 0;
    int max_profit = 0;
    int max_buy_idx = 0;
    int max_sell_idx = 0;
    while(sell < pricesSize) {
        if (prices[buy] < prices[sell]) {
            profit = prices[sell] - prices[buy];
            if (profit > max_profit) {
                max_profit = profit;
                max_buy_idx = buy;
                max_sell_idx = sell;
            }
        }
        else {
            buy = sell;
        }
        sell++;
    }
    return max_profit;
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
}
