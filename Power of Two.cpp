//Given an integer, write a function to determine if it is a power of two.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n > 0 && n % 2 == 0) {
            n /= 2;
        }
        return n % 2 == 0 || n == 1;
    }
};
