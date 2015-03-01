//大神的方法真是好
// Implement wildcard pattern matching with support for '?' and '*'.

// '?' Matches any single character.
// '*' Matches any sequence of characters (including the empty sequence).

// The matching should cover the entire input string (not partial).

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *start = NULL;
        const char *ss = s;
        while (*s) {
            if (*p == '?' || *s == *p) {
                s++; p++;
                continue;
            }
            if (*p == '*') {
                start = p;
                ss = s;
                p++;
                continue;
            }
            if (start) {
                p = start + 1;
                s = ss + 1;
                ss++;  // important
                continue;
            }
            return false;
        }
        while (*p == '*')
            p++;
        return *p == '\0';
    }
};
