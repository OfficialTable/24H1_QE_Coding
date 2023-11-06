def maxProfit(prices:List[int])-> int:
    profit = 0
    buy = prices[0]
    for i in range(1, len(prices)):
        sell = prices[i]
        potential = sell - buy
        if buy > sell:
            buy = sell
        elif potential > profit:
            profit = potential
    return profit