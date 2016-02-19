//Say you have an array for which the ith element is the price of a given stock on day i.

//Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

//You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
//Example:
//prices = [1, 2, 3, 0, 2]
//maxProfit = 3
//transactions = [buy, sell, cooldown, buy, sell]

//buy[i] = max(rest[i-1] - price, buy[i-1]);
//sell[i] = max(buy[i-1] + price, sell[i-1]);
//rest[i] = max(sell[i-1] - buy[i-1], rest[i-1]);

//because buy[i] <= rest[i] so that rest[i] = max(sell[i-1],  rest[i-1])
//since we have cooldown, so that rest[i] = sell[i-1];

//buy[i] = max(sell[i-2] - price, buy[i-1]);
//sell[i] = max(buy[i-1] + price, sell[i-1]);

int maxProfit(vector<int>& prices) {
    int buy = INT_MIN, pre_buy = 0, sell = 0, pre_sell = 0;
    for (auto price : prices) {
        pre_buy = buy;
        buy = max(pre_sell - price, buy);
        pre_sell = sell;
        sell = max(sell + price, sell);
    }
    return sell;
}
