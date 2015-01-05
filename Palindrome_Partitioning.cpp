class Solution {
public:
    bool isPld(string s) {
        for (int i = 0; i< s.length()/2; i++) {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
    
    bool helper(string s, vector<string> &tmp, vector<vector<string> > &res) {
        if (s == "")    return true;
        for (int i = 0; i < s.length(); i++) {
            for (int len = 1; len <= s.length()- i; len++) {
                if (isPld(s.substr(0, len))) {
                    tmp.push_back(s.substr(0, len));
                    if (helper(s.substr(len), tmp, res))
                        res.push_back(tmp);
                    tmp.pop_back();
                }
            }
            return false;
        }
        return false;
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        vector<vector<string>> res;
        helper(s, tmp, res);
        return res;
    }
};
