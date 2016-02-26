//大神的方法真是好
// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, match = 0, star = -1;
        while (i < s.length()) {
            if (j < p.length() && p[j] == '*') {
                star = j++;
                match = i; // i don't advance is for case * match empty space
                continue;
            }
            if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
                continue;
            }
            if (star >= 0) { //stop match for * until s[i] == p[j] || p[j] == '?'
                i = ++match;
                j = star + 1;
                continue;
            }
            return false;
        }
        while (j < p.length() && p[j] == '*')
            j++;
        return j == p.length();
    }
};
