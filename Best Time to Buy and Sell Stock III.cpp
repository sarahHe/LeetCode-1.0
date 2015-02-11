// Say you have an array for which the ith element is the price of a given stock on day i.
// Design an algorithm to find the maximum profit. You may complete at most two transactions.

// 首先，因为能买2次（第一次的卖可以和第二次的买在同一时间），但第二次的买不能在第一次的卖左边。
// 所以维护2个表，f1和f2，size都和prices一样大。
// 意义：
// f1[i]表示 -- 截止到i下标为止，左边所做交易能够达到最大profit；
// f2[i]表示 -- 截止到i下标为止，右边所做交易能够达到最大profit；
// 那么，对于f1 + f2，寻求最大即可。
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        vector<int> left (prices.size(), 0),
                    right (prices.size(), 0);
        int mins = prices[0], maxs = prices.back();
        for (int i = 1; i< prices.size(); i++) {
            //left[i]: so far the maxProfit from left
            left[i] = max(left[i-1], prices[i] - mins); 
            mins = min(mins, prices[i]);
            
            //right[i]: so far the maxProfit from right
            right[prices.size() - i - 1] = max(right[prices.size() - i - 1], maxs - prices[prices.size() - i -1]);
            maxs = max(maxs, prices[prices.size() - i-1]);
        }
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++)
            maxProfit = max(maxProfit, left[i]+right[i]);
        return maxProfit;
    }
};
