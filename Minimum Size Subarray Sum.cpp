// Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, len = INT_MAX, begin = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                len = min(len, i - begin + 1); // this line should be before the next line
                sum -= nums[begin++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};
