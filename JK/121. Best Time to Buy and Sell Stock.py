def maxProfit(prices):
    cur = prices[0]
    ans = 0

    for i in range(1,len(prices)):
        if cur > prices[i]:
            cur = prices[i]
        ans = max(ans, prices[i]-cur)

    return ans

        # 시간 초과
        # ans = 0
        # for i in range(len(prices)):
        #     for k in range(i,len(prices)):
        #         if prices[i] < prices[k]:
        #             val = prices[k] - prices[i]
        #             ans = max(ans, val)

        # return ans


# prices = [7,1,5,3,6,4]
# maxProfit(prices)