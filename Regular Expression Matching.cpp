// Implement regular expression matching with support for '.' and '*'.

// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.

// The matching should cover the entire input string (not partial).

// The function prototype should be:
// bool isMatch(const char *s, const char *p)

// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

class Solution {
// 如果P[j+1]!='*'，S[i] == P[j]=>匹配下一位(i+1, j+1)，S[i]!=P[j]=>匹配失败；
// 如果P[j+1]=='*'，S[i]==P[j]=>匹配下一位(i+1, j+2)或者(i, j+2)，S[i]!=P[j]=>匹配下一位(i,j+2)。
// 匹配成功的条件为S[i]=='\0' && P[j]=='\0'。
public:
    bool isMatch(const char *s, const char *p) {
        // const char ! can't s_copy = s
        if (*p == '\0')
            return *s == '\0';
        
        if (*(p+1) == '*') {
            while (*s == *p || (*s != '\0' && *p == '.')) {
                if (isMatch(s, p+2)) //check when '*' represent nothing
                                    //and start find since p+2
                    return true;
                s++;
            }
            return isMatch(s, p+2); //important
        }
        else if ((*s == *p) || (*s != '\0' && *p == '.'))
            //'.' can match any char including '\0'
            return isMatch(s+1, p+1);
            
        return false;
    }
};



2016.2.26
bool isMatch(string s, string p) {
    if (p.empty())  return s.empty();
    
    if (p[1] == '*') {
        return isMatch(s, p.substr(2)) ||
                (!s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p) );
    }
    else {
        return !s.empty() && (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); 
    }
}
