// Given a set of candidate numbers (C) and a target number (T), 
// find all unique combinations in C where the candidate numbers sums to T.
// The same repeated number may be chosen from C unlimited number of times.
// Note:
// All numbers (including target) will be positive integers.
// Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
// The solution set must not contain duplicate combinations.

class Solution {
public:
    void helper(vector<int> &candidates, int target, int sum, vector<vector<int>> &res, vector<int> &tmp, int pos) {
        if (sum > target)
            return;
            
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = pos; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            helper(candidates, target, sum + candidates[i], res, tmp, i);
            tmp.pop_back();
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, res, tmp, 0);
        return res;
    }
};
