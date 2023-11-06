#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int max_profit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[i - 1]) {
            max_profit += prices[i] - prices[i - 1];
        }
    }

    return max_profit;
    
}

int main() {
    // Example usage:
    int prices[] = {7, 1, 5, 3, 6, 4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int profit = maxProfit(prices, pricesSize);
    printf("Maximum Profit: %d\n", profit);

    return 0;
}