// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the emtpy string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() < T.length())    return "";
        
        int expected[256] = {0}, found[256] = {0},
            count = 0, k = 0, start = 0,
            miniLen = INT_MAX;
        for (int i = 0; i < T.length(); i++) {
            expected[T[i]]++;
        }
        
        for (int i = 0; i < S.length(); i++) {
            if (expected[S[i]] == 0) 
                continue; 
                
            found[S[i]]++;
            if (found[S[i]] <= expected[S[i]]) // ++ is before this, so need =
                count++;
    
            if (count == T.length()) { 
                while (expected[S[k]] == 0 || found[S[k]] > expected[S[k]]) {
                    // expected[S[k] is to ignore unexpected ones; 
                    // found[S[i]] > expected[S[i]] is to ignore the repeated char
                    if (found[S[k]] > expected[S[k]]) {
                        found[S[k]]--;
                    }
                    k++;
                }
                if (i - k + 1 < miniLen) {
                    miniLen = i - k + 1;
                    start = k;
                }
            } // no need to decrease count
        }
        if (miniLen == INT_MAX) return "";
        return S.substr(start, miniLen);
    }
};
