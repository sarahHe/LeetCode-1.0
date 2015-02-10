// Given two words word1 and word2, find the minimum number of steps 
// required to convert word1 to word2. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character

// 思路：
// 如果我们用 i 表示当前字符串 A 的下标，j 表示当前字符串 B 的下标。 
// 如果我们用d[i, j] 来表示A[1, ... , i] B[1, ... , j] 之间的最少编辑操作数。那么我们会有以下发现：
// 1. d[0, j] = j;
// 2. d[i, 0] = i;
// 3. d[i, j] = d[i-1, j - 1] if A[i] == B[j]
// 4. d[i, j] = min(d[i-1, j - 1], d[i, j - 1], d[i-1, j]) + 1  if A[i] != B[j]

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.size()+1, vector<int> (word2.size()+1, 0));
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i; //pay attention
        for (int i = 0; i <= word2.size(); i++)
            dp[0][i] = i; // pay attention
        
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
        return dp.back().back();
    }
};
