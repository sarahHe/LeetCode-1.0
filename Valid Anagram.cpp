// Given two strings s and t, write a function to determine if t is an anagram of s.

// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())   return false;
        
        int arr[256] = {0}; //must initialize to 0
        for (int i = 0; i < s.length(); i++) {
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for (auto i : s) {
            if (arr[i-'a'])
                return false;
        }
        return true;
    }
};
