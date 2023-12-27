'''
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
'''

def maxProfit(prices: list ) -> int:
    len_prices = len(prices)
    profit = 0
    buy = 0
    sell = 0
    max_profit = 0
    max_buy_idx = 0
    max_sell_idx = 0
    while sell < len_prices:
        if prices[buy] < prices[sell]:
            profit = prices[sell] - prices[buy]
            if profit > max_profit:
                max_profit = profit
                max_buy_idx = buy
                max_sell_idx = sell
        else :
            buy = sell
        sell += 1
        # print(buy, sell, max_buy_idx, max_sell_idx, profit, max_profit)
    return max_profit

    # ##### Too Time-consuming code #####
    # for buy in range(len_prices):
    #     for sell in range(buy+1, len_prices):
    #         if prices[sell] > prices[buy]:
    #             profit = prices[sell] - prices[buy]
    #         if profit > max_profit:
    #             max_profit = profit
    #             max_buy_idx = buy
    #             max_sell_idx = sell
    # return max_profit

if __name__ == "__main__":
    print("121_BestTimeToBuyAndSellStock.py")
    print("\nCase 1")
    nums1 = [7,1,5,3,6,4]
    ans = 5
    res = maxProfit(nums1)
    print(res, "\n==> check: ", res==ans)

    print("\nCase 2")
    nums1 = [7,6,4,3,1]
    ans = 0
    res = maxProfit(nums1)
    print(res, "\n==> check: ", res==ans)

