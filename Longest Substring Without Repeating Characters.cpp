class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, maxLen = 0;
        vector<int> table(256, -1);
        int i = 0;
        for (int i = 0; i < s.length(); i++) {
            while (i < s.length() && table[s[i]] < start) {
                table[s[i]] = i;
                i++;
            }
            
            maxLen = max(maxLen, i - start);
            if (i < s.length()) {
                start = table[s[i]] + 1;
                table[s[i]] = i;
            }
        }
        return maxLen;
    }
};


2015.5.24 update
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")    return 0;
        vector<int> m(256, -1);
        int len = 0, start = -1, i;
        for (i = 0; i < s.length(); ++i) {
            if (m[s[i]] >= start) //repeat
                start = m[s[i]] + 1;
            m[s[i]] = i;
            len = max(len, i - start + 1);
        }
        return len;
    }
};
