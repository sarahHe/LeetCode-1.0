// Description:

// Count the number of prime numbers less than a non-negative number, n
// References:
// How Many Primes Are There?

// Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)  return 0;
        
        int count = 1; // starts from 1, which refers to number 2
        vector<bool> prime(n, true);
        for (int i = 3; i < n; i += 2) { // i = 3 refers to number 4
            if (prime[i] == false) // number 4 is not a prime but this time we count for number 3
                continue;
            
            count++;
            if (i > sqrt(n))    continue; // to avoid overflow
            for (int j = i * i; j < n; j += i) 
                prime[j] = false;
        }
        return count;
    }
};
