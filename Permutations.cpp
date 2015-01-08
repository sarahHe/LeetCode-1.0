class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &tmp, vector<int> &num) {
        if (num.empty())
            res.push_back(tmp);
        else {
            for (int i = 0; i < num.size(); i++) {
                tmp.push_back(num.front());
                num.erase(num.begin());
                helper(res, tmp, num);
                num.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, num);
        return res;
    }
};
