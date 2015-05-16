//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//For example, given the range [5, 7], you should return 4.

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (m < n) {
            n &= n - 1; //有一个很明显很明显的规律。就是n & (n-1)的话永远会把n的最后一个1给消除掉。
        }   
        return n;
    }
};
