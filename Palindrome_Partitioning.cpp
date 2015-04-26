// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// For example, given s = "aab",
// Return

//   [
//     ["aa","b"],
//     ["a","a","b"]
//   ]
class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void dfs(vector<vector<string>> &res, vector<string> &tmp, int pos, string &s) {
        if (pos == s.length()){
            res.push_back(tmp);
            return; 
        }  
        
        for (int i = pos; i < s.length(); ++i) {
            if (!isPalindrome(s, pos, i)) 
                continue;
                
            tmp.push_back(s.substr(pos, i - pos + 1));
            dfs(res, tmp, i+1, s); // i+1 rather than pos+1
            tmp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if (s == "")    return res;
        
        vector<string> tmp;
        dfs(res, tmp, 0, s);
        return res;
    }
};
