// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Ensure that numbers within the set are sorted in ascending order.
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> sol;
        combinationHelper(res, sol, k, n);
        return res;
    }
    
    void combinationHelper(vector<vector<int>> &res, vector<int> sol, int k, int n) {
        if (sol.size() == k && n == 0)  {
            res.push_back(sol);
            return;
        }
        
        for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; i++) {
            sol.push_back(i);
            combinationHelper(res, sol, k, n - i);
            sol.pop_back();
        }
        
    }
};
