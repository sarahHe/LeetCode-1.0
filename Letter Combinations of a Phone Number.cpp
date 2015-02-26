//classical DP
class Solution {
public:
    void generate(string digits, vector<string> trans, int pos, string tmp, vector<string> &res) {
        if (pos == digits.length()) {
            res.push_back(tmp);
            return;
        }

        int dg = digits[pos] - '0';
        for (int j = 0; j < trans[dg].length(); j++) {
            generate(digits, trans, pos+1, tmp+trans[dg][j], res);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> trans = {"", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  \
        vector<string> res;
        if (digits == "")
            return res;
        generate(digits, trans, 0,"", res);
        return res;
    }
};
