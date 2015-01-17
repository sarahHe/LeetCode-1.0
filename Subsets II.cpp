/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

这个思路略有一点动态规划的思想。有用DFS的方法
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        if (S.empty()) return res;
        
        sort(S.begin(), S.end());
        vector<int> tmp;
        res.push_back(tmp);
        set<vector<int>> unique = {tmp};
        for (int i = 0; i < S.size(); i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                tmp = res[j];
                tmp.push_back(S[i]);
                if (unique.find(tmp) == unique.end()) {
                    res.push_back(tmp);
                    unique.insert(tmp);
                }
            }
        }
        return res;
    }
};
