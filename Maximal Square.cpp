// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

// to give a square of size larger than 1 in P[1][1], all of its three neighbors (left, up, left-up) should be non-zero
// Taking all these together, we have the following state equations.
// P[0][j] = matrix[0][j] (topmost row);
// P[i][0] = matrix[i][0] (leftmost column);
// For i > 0 and j > 0: if matrix[i][j] = 0, P[i][j] = 0; if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())    return 0;
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSize = 0;
        for (int i=0; i<m; i++) {
            dp[0][i] = matrix[0][i] - '0';
            maxSize = max(maxSize, dp[0][i]);
        }
        for (int i=0; i<n; i++) {
            dp[i][0] = matrix[i][0] - '0';
            maxSize = max(maxSize, dp[i][0]);
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] =='0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                    maxSize = max(maxSize, dp[i][j]);
                }
            }
        }
        return maxSize * maxSize;
    }
};
