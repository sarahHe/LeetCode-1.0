class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<int> dp(obstacleGrid[0].size() + 1, 0);
    dp[1] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 0; i < obstacleGrid.size(); i++) {
        for (int j = 1; j <= obstacleGrid[0].size(); j++)
            if (obstacleGrid[i][j-1] == 0)
                dp[j] += dp[j-1];
            else
                dp[j] = 0;
    }
    return dp.back();
}

};
