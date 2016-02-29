// Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
// Formally the function should:
// Return true if there exists i, j, k 
// such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
// Your algorithm should run in O(n) time complexity and O(1) space complexity.

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n1 = INT_MAX, n2 = INT_MAX;
        for (auto i : nums) {
            if (i <= n1) // n1 is min seen so far (it's a candidate for 1st element)
                n1 = i;
            else if (i <= n2) // here when i > n1, i.e. x might be either n2 or n3
                n2 = i; // i is better than the current c2, store it
            else // here when we have/had c1 < c2 already and x > c2
                return true; // the increasing subsequence of 3 elements exists
        }
        return false;
    }
};
