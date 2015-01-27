// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct
// ways can you climb to the top?

// 利用DP的方法，一个台阶的方法次数为1次，两个台阶的方法次数为2个。
// n个台阶的方法可以理解成上n-2个台阶，然后2步直接上最后一步；
// 或者上n-1个台阶，再单独上一步。
// 公式是S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i=2; i<n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp.back();
    }
};
