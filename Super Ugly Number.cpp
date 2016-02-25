//Write a program to find the nth super ugly number.
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
//For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super 
//ugly numbers given primes = [2, 7, 13, 19] of size 4.

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n, 0), idx(primes.size(), 0);
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = INT_MAX; // must have
            for (int j = 0; j < primes.size(); j++) {
                res[i] = min(primes[j]*res[idx[j]], res[i]);
            }
            
            for (int j = 0; j < primes.size(); j++) {
                if (res[i] == primes[j] * res[idx[j]])
                    idx[j]++;
            }
        }
        return res.back();
    }
};
