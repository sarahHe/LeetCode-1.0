// Divide two integers without using multiplication, 
// division and mod operator.
// If it is overflow, return MAX_INT.

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long d1 = dividend, d2 = divisor;
        d1 = abs(d1); d2 = abs(d2);
        int res = 0, count = 1;
        while (d1 >= d2) { // this while is for case when res == 0
            long tmp = d2; // !!!
            count = 1;
            while (tmp + tmp <= d1) {
                tmp += tmp;
                count += count;
            }
            res += count;
            d1 -= tmp;
        }
        // more careful about INT_MIN, INT_MAX
        if (dividend < 0 ^ divisor < 0) {
            if (res == INT_MIN)
                return res;
            else
                return -res;
        }
        else {
            if (-res == INT_MIN)
                return INT_MAX;
            else
                return res;    
        }
            
    }
};
