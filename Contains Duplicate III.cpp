// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> mySet;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                mySet.erase(nums[i-k-1]);
                
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto pos = mySet.lower_bound(nums[i] - t);
            if (pos != mySet.end() && *pos - t <= nums[i])  return true; // pos <= nums[i] + t would exceed scope
            
            mySet.insert(nums[i]);
        }
        return false;
    }
};
