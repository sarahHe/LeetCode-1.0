class Solution {
public:
    void breakWord(vector<string> &res, string &s, unordered_set<string> &dict, string str, int pos, vector<bool> &dp) {
        if (pos == s.length()) {
            res.push_back(str.substr(0, str.length()-1));
            return;
        }
        
        for (int i = pos; i < s.length(); ++i) {
            string substr = s.substr(pos, i-pos+1); // substr starts from pos
            if (dp[i+1] && dict.count(substr) > 0)  // check dp[i+1] not dp[i]
                breakWord(res, s, dict, str + substr + " ", i+1, dp);
        }
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.length(); ++i) {
            if (dp[i]) {
                for (int len = 1; i + len < s.length() + 1; ++len) {
                    if (dict.count(s.substr(i, len)) > 0) {
                        dp[i + len] = true;
                    }
                }
            }
        }
        vector<string> res;
        if (dp[s.length()]) //important
            breakWord(res, s, dict, "", 0, dp);
        return res;
    }
};
