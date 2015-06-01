// Given a string containing only digits, restore it by 
// returning all possible valid IP address combinations.

// For example:
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


// ip address should be [0,255]
//be careful about the precondition before doing anything
2015.5.31 update
class Solution {
public:
    bool isValid(string sub) {
        if (sub.length() == 1)
            return sub >= "0" && sub <= "9"; // for case like 01
        else if (sub.length() == 2)
            return sub >= "10" && sub <= "99";
        else 
            return sub >= "100" && sub <= "255";
    }

    void restore(vector<string> &res, string tmp, string s, int pos, int count) {
        if (count == 4 && pos < s.length()) return;
        
        if (count == 4 && pos == s.length()) {
            res.push_back(tmp.substr(1));
            return;
        }
    
        for (int j = 1; j <= 3 && pos + j <= s.length(); j++) {
            string sub = s.substr(pos, j);
            if (isValid(sub)) {
                restore(res, tmp + "." + sub, s, pos + j, count + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s == "")    return res;
        restore(res, "", s, 0, 0);
        return res;
    }
};
