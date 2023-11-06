#include <stdio.h>
#include <limits.h> // INT_MAX

int maxProfit(int* prices, int pricesSize) {
    int cur = prices[0];
    int ans = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (cur > prices[i]) {
            cur = prices[i];
        }
        int profit = prices[i] - cur;
        if (profit > ans) {
            ans = profit;
        }
    }

    return ans;
}

int main() {
    // Example usage:
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int profit = maxProfit(prices, pricesSize);
    printf("Maximum Profit: %d\n", profit);

    return 0;
}
