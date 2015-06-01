// Implement pow(x, n).
// 1) x取值为0时，0的正数次幂是1，而负数次幂是没有意义的；判断x是否等于0不能直接用“==”。
// 2) 对于n取值INT_MIN时，-n并不是INT_MAX，这时需要格外小心。
// 3) 尽量使用移位运算来代替除法运算，加快算法执行的速度。

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0; //double
        if (n < 0) {
            if (n == INT_MIN)
                return 1.0 / (myPow(x, INT_MAX) * x); // case!
            else
                return 1.0 / myPow(x, -n);
        } else if (n > 0) {
            while (n) {
                if (n % 2 == 1) 
                    res *= x;
                    
                x *= x;//x *= x rather than res *= res
                n /= 2;
            }
        }
        return res;
    }
};
