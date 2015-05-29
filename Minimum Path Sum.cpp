class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size()+1, INT_MAX);
        dp[1] = 0;//dp[1] = 0 rather than dp[0] = 0, since we need INT_MAX for 1st elemen in every level
        for (int i = 0; i< grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                dp[j+1] = grid[i][j] + min(dp[j+1], dp[j]);
            }
        }
        return dp.back();
    }
};
