int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int buy = prices[0];
    for(int i=1; i<pricesSize; i++){
        int sell = prices[i];
        int potential = sell - buy;
        if(buy>sell){buy = sell;}
        if(potential>profit){profit=potential;}
    }
    return profit;
}