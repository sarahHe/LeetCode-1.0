//There is a fence with n posts, each post can be painted with one of the k colors.
//You have to paint all the posts such that no more than two adjacent fence posts have the same color.
//Return the total number of ways you can paint the fence.
//Note: n and k are non-negative integers.


//dp1[i]=dp2[i-1],
//dp2[i]=(k-1)(dp1[i-1]+dp2[i-1]) =(k-1)(dp2[i-2]+dp2[i-1])
//Final result is dp1[n-1]+dp2[n-1];

int numWays(int n, int k) {
    if (n == 0) return 0;
    vector<int> dp = {0, k, k*k, 0};
    for (int i = 2; i < n; i++) {
        dp[3] = (k-1) * (dp[1] + dp[2]);
        dp[1] = dp[2];
        dp[2] = dp[3];
    }
    return dp[3];
}
