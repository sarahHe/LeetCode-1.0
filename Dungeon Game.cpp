class Solution {
// each grid has different value, can't use 1D dp
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));//dp[i][j]表示从(i,j)到目的地(m-1,n-1)需要的最小生命值
        dp[m-1][n-1] = max(0, 0 - dungeon[m-1][n-1]);
        for (int i = m - 2; i >= 0; i--)
            dp[i][n-1] = max(0, dp[i+1][n-1] - dungeon[i][n-1]);
        for (int i = n - 2; i >= 0; i--)
            dp[m-1][i] = max(0, dp[m-1][i+1] - dungeon[m-1][i]);
        
        //从下向上，从右向左填表
        //dp方程为  dp[i][j] = min(dp[i][j+1], dp[i+1][j]) - dungeon[i][j] 再和0取最大
        for (int i = m-2; i>= 0; i--) {
            for (int j = n-2; j>=0; j--) {
                dp[i][j] = max(min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j], 0);
            }
        }
        return dp[0][0]+1;
    }
};



2015.4.18 update
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.empty() || dungeon[0].empty())  return 0;
        
        vector<vector<int> > D(dungeon.size() + 1, vector<int> (dungeon[0].size() + 1, INT_MAX));
        D[D.size() - 1][D[0].size() - 2] = 1;
        D[D.size() - 2].back() = 1;
        for (int i = dungeon.size() - 1; i >= 0; i--) {
            for (int j = dungeon[0].size() - 1; j >= 0; j--) {
                int min_safe_exit = min(D[i+1][j], D[i][j+1]);
                D[i][j] = max(min_safe_exit - dungeon[i][j], 1);
            }
        }
        return D[0][0];
    }
};

// we can use the original dungeno for DP data storage. Use O(mn) time, O(1) memory.
class Solution {
    public:
      int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        dungeon[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : abs(dungeon[m - 1][n - 1]) + 1;
        for (int i = n-2; i >= 0; --i)
          dungeon[m - 1][i] = max(dungeon[m - 1][i + 1] - dungeon[m - 1][i],1);
        for (int i = m - 2; i >= 0; --i)
          dungeon[i][n - 1] = max(dungeon[i + 1][n - 1] - dungeon[i][n - 1],1);
        for (int i = m-2; i >= 0;--i)
          for (int j = n-2; j >= 0; --j)
            dungeon[i][j] = max(min(dungeon[i + 1][j], dungeon[i][j + 1]) - dungeon[i][j],1);
        return dungeon[0][0];
      }
 };
