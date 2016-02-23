// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> mySet;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                mySet.erase(nums[i - k - 1]);
            if (mySet.count(nums[i]) > 0)
                return true;
            mySet.insert(nums[i]);
        }
        return false;
    }
};
