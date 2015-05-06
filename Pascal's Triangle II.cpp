// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return [1,3,3,1].
// Note:
// Could you optimize your algorithm to use only O(k) extra space?

// use a tmp vector to store the previous info
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 0);
        dp[0] = 1;
        vector<int> tmp = dp;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j < i; j++) 
                dp[j+1] += tmp[j];
            tmp = dp;
        }
        return dp;
    }
};


2015.5.5 update
//reduce time from 6ms to 3ms
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for (int i = 0; i <= rowIndex; i++) 
            for (int j = i; j > 0; j--)
                res[j] += res[j-1];
        return res;
    }
};
