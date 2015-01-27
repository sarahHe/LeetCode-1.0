// Given an integer n, return the number of trailing zeroes in n!.
// Note: Your solution should be in logarithmic time complexity.

// 分解因子, 当且仅当 因子中出现 一对 (2,5)时, 最后结果会增加一个 trailing zero.
// 1.  2的个数永远多于5个个数.
// 2.  计算5的个数时, 最简单的方法是 SUM(N/5^1,  N/5^2, N/5^3...)

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 0)
            return 0;
        int count = 0;
        while (n) {
            n /= 5;
            count += n;
        }
        return count;
    }
};
