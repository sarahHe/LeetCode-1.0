// Given a string containing only digits, restore it by 
// returning all possible valid IP address combinations.

// For example:
// Given "25525511135",
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


// ip address should be [0,255]
//be careful about the precondition before doing anything
class Solution {
public:
    bool isValid(string num) {
        if (num.length() == 1)
            return num >= "0" && num <= "9";
        else if (num.length() == 2)
            return num >= "10" && num <= "99";
        else if (num.length() == 3)
            return num >= "100" && num <= "255";
        else
            return false;
    }
    
    void helper(string s, vector<string> &res, string tmp, int k) {
        if (k == 3) {
            if (isValid(s)) {
                tmp += '.'+s;
                res.push_back(tmp.substr(1));
            }
            return;
        }
        
        for (int i=1; i<4; i++) {
            if (s.length() >= i && isValid(s.substr(0,i))) {
                helper(s.substr(i), res, tmp +'.'+ s.substr(0, i), k+1);
            }
            else
                return;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        vector<string>  res;
        if (s.length() < 4 || s.length() > 12)
            return res;
        
        helper(s, res, "", 0);
        return res;
    }
};


2015.3.11 update // although it's not as clean as the previous one
bool isValid(string s) {
    if (s.length() == 1)
        return s >= "0" && s <= "9";
    if (s.length() == 2)
        return s >= "10" && s <= "99";
    if (s.length() == 3)
        return s >= "100" && s <= "255";
    return false;
}

void restore_helper(vector<string> &res, string tmp, string s, int pos, int count) {
    if (count == 4) {
        if (pos == s.length())
            res.push_back(tmp.substr(1));
        return;
    }
    
    for (int i = 1; i <= 3; i++) {
        if (pos + i > s.length() || !isValid(s.substr(pos, i)))
            return;
    
        restore_helper(res, tmp + "." + s.substr(pos, i), s, i + pos, count + 1);
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string>  res;
    if (s.length() < 4 || s.length() > 12)
        return res;
    restore_helper(res, "", s, 0, 0);
    return res;
}
