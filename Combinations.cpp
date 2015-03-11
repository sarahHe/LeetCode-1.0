// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// For example,
// If n = 4 and k = 2, a solution is:

// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
class Solution {
public:
    void combine_helper(vector<vector<int> > &res, vector<int> tmp, int pos, int n, int k) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = pos; i<= n; i++) {
            tmp.push_back(i);
            combine_helper(res, tmp, i + 1, n , k);
            tmp.pop_back(); // important
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> tmp;
        combine_helper(res, tmp, 1, n, k);
        return res;
    }
};
