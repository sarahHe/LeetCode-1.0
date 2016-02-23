class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> mySet;
        for (auto i : nums) {
            if (mySet.count(i) > 0)
                return true;
            mySet.insert(i);
        }
        return false;
    }
};
