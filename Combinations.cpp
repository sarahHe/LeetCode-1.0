class Solution {
public:
    void helper(vector<vector<int> > &res, vector<int> &tmp, int n, int j, int k) {
        if (!k) res.push_back(tmp);
        
        for (int i = j; i <= n; i++) {
            // if (tmp.find(i) != tmp.end())   continue;
            tmp.push_back(i);
            helper(res, tmp, n, i + 1, k - 1);
            tmp.pop_back();
        }
    }

    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        if (!n || n < k || n < 1 || k < 1)    return res;
        
        vector<int> tmp;
        helper(res, tmp, n, 1, k);
        return res;
    }
};
