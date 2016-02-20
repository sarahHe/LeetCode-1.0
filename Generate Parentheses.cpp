class Solution {
public:
    void generator(int left, int right, int n, string tmp, vector<string> &res) {
        if (left + right == 2*n)
            res.push_back(tmp);
            
        if (left < n)
            generator(left+1, right, n, tmp+"(", res); // order doesn't matter
        if (right < left)
            generator(left, right+1, n, tmp+")", res); // order doesn't matter
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n > 0)
            generator(0, 0, n, "", res);
        return res;
    }
};
