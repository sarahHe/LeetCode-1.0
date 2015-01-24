// Implement pow(x, n).
// 1) x取值为0时，0的正数次幂是1，而负数次幂是没有意义的；判断x是否等于0不能直接用“==”。
// 2) 对于n取值INT_MIN时，-n并不是INT_MAX，这时需要格外小心。
// 3) 尽量使用移位运算来代替除法运算，加快算法执行的速度。

class Solution {
public:
    double pow(double x, int n) {
        double res = 1.0;
        
        if (n < 0) {
            if (n == INT_MIN)
                return 1.0/(pow(x, INT_MAX) * x);
            else
                return 1.0/pow(x, -n);
        }
        else if (n > 0) {
            while (n) {
                if (n % 2 != 0) 
                    res *= x;
                
                x *= x;
                n /= 2;
            }
        }
        return res;
    }
};
