// Given a sorted integer array without duplicates, return the summary of its ranges.
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())   return res;

        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            
            while (i < nums.size()-1 && 1 == nums[i+1] - nums[i])
                i++;
            if (a != nums[i])
                res.push_back(to_string(a) + "->" + to_string(nums[i]));
            else
                res.push_back(to_string(a) + "");
        }
        return res;
    }
};
