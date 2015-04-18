// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

// "n &= n - 1" is used to delete the right "1" of n. For example:

// if n = 5 (101), then n-1 = 100, so n & (n-1) = 100, the right "1" is deleted;
// if n = 6,(110), then n-1 = 101, so n & (n-1) = 100, the right "1" is also deleted;
// and so on...
// So time complexity is O(m), and m is the count of 1's, also m is less than or equal to 32.
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= n-1;
            count++;
        }
        return count;
    }
};
