// local[i][j]和global[i][j]的区别是：local[i][j]意味着在第i天一定有交易（卖出）发生，当第i天的价格高于第i-1天（即diff > 0）时，那么可以把这次交易（第i-1天买入第i天卖出）跟第i-1天的交易（卖出）合并为一次交易，即local[i][j]=local[i-1][j]+diff；当第i天的价格不高于第i-1天（即diff<=0）时，那么local[i][j]=global[i-1][j-1]+diff，而由于diff<=0，所以可写成local[i][j]=global[i-1][j-1]。global[i][j]就是我们所求的前i天最多进行k次交易的最大收益，可分为两种情况：如果第i天没有交易（卖出），那么global[i][j]=global[i-1][j]；如果第i天有交易（卖出），那么global[i][j]=local[i][j]。

// 这道题还有一个陷阱，就是当k大于天数时，其实就退化成 Best Time to Buy and Sell Stock II 了。就不能用动规来做了，
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (k >= size/2)    return solveMaxProfit(prices);
        
        vector<int> local(k+1, 0), global(k+1, 0); 
        for (int i = 0; i < size - 1; i++) {
            int tmpProfit = prices[i+1] - prices[i];
            for (int j = 1; j <= k; j++) {
                local[j] = max(local[j] + tmpProfit, global[j-1]);
                global[j] = max(local[j], global[j]);
            }
        }
        return global.back();
    }
    
private:
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};
