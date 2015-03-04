/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

// 和Subsets I的唯一区别就是添加了两行去重的代码。
class Solution {
public:
    void generate(vector<int> &S, int pos, vector<int> &tmp, vector<vector<int> > &res) {
        res.push_back(tmp);
        for (int i = pos; i < S.size(); i++) {
            if (i > pos && S[i] == S[i-1])
                continue;
            tmp.push_back(S[i]);
            generate(S, i+1, tmp, res); // i+1
            tmp.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        vector<int> tmp;
        sort(S.begin(), S.end());
        generate(S, 0, tmp, res);
        return res;
    }
};
