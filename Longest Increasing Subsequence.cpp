class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto i : nums) {
            auto it = lower_bound(res.begin(), res.end(), i); 
            //Lower_bound is a version of binary search: it attempts to find the element value in an ordered range [first, last) [1]. Specifically, it returns the first po
            if (it == res.end())
                res.push_back(i);
            else
                *it = i;
        }
        return res.size();
    }
};
