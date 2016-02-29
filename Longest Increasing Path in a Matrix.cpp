// Given an integer matrix, find the length of the longest increasing path.
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
// Example 1:
// nums = [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ]
// Return 4
// The longest increasing path is [1, 2, 6, 9].

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())    return 0;
        int maxLen = 1;
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int len = pathHelper(matrix, i, j, cache);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
    
    int pathHelper(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache) {
        if (cache[i][j] != 0)   return cache[i][j]; // cache is important here! to avoid repeated calculation
        
        int maxLen = 1;
        if (i > 0 && matrix[i][j] < matrix[i-1][j]) {
            int len = pathHelper(matrix, i-1, j, cache) + 1;
            maxLen = max(maxLen, len);
        }
        if (i < matrix.size() - 1 && matrix[i][j] < matrix[i+1][j]) {
            int len = pathHelper(matrix, i+1, j, cache) + 1;
            maxLen = max(maxLen, len);
        }
        if (j > 0 && matrix[i][j] < matrix[i][j-1]) {
            int len = pathHelper(matrix, i, j-1, cache) + 1;
            maxLen = max(maxLen, len);
        }
        if (j < matrix[0].size() - 1 && matrix[i][j] < matrix[i][j+1]) {
            int len = pathHelper(matrix, i, j+1, cache) + 1;
            maxLen = max(maxLen, len);
        }
        cache[i][j] = maxLen;
        return maxLen;
    }
};
