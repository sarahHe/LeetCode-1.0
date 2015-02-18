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
