// Write an algorithm to determine if a number is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Example: 19 is a happy number

// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

//happy number only have four round
//unhappy number falls to the integer[2,6]
//use map
//below is the fastest way
class Solution {
public:
    int next(int n) {
        int res = 0;
        while (n) {
            int t = n % 10;
            res += t * t;
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) {
        int l1 = n, l2 = next(n);
        while (l1 != l2) {
            l1 = next(l1);
            l2 = next(next(l2));
        }
        return l1 == 1;
    }
};
