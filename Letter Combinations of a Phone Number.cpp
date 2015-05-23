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


2015.5.22 update
class Solution {
public:
    void combine(string &digits, int pos, vector<string> &res, string tmp) {
        if (tmp.length() == digits.length())
            res.push_back(tmp);
            
        for (int i = pos; i < digits.length(); i++) {
            for (auto j : letter[digits[i] - '0']) {
                tmp += j;
                combine(digits, i + 1, res, tmp);
                tmp.resize(tmp.length() - 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "")   return vector<string>();
        
        vector<string> res;
        combine(digits, 0, res, "");
        return res;
    }
private:
    vector<string> letter = {"--", "--", "abc", "edf", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // make use of private data could speed up a little bit
};
