class Solution {
public:
    void helper(string digits, string tmp, unordered_map<char, vector<char>>&maps, vector<string> &res, int n) {
        if (tmp.length() == n) {
            res.push_back(tmp);
            return;
        }
        
        for (int i = 0; i < digits.length(); i++) {
            string digits_copy = digits;
            for (int j = i; j < maps[digits[i]].size(); j++) {
                helper(digits_copy.substr(i+1), tmp + maps[digits[i]][j], maps, res, n);
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, vector<char>> maps =
        {{'2', {'a','b','c'}}, {'3', {'d','e','f'}}, {'4', {'g','h','i'}},
            {'5', {'j','k','l'}}, {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}}, {'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}}};
        
        vector<string> res;
        helper(digits, "", maps, res, digits.length());
        for (auto i : res)
            cout << i << endl;
        return res;
    }
};
