class Solution {
public:
    string minWindow(string S, string T) {
        if (S.length() < T.length())
            return "";
        
        unordered_map<char, int> expect, found;
        for (auto i : T)
            expect[i]++;
        int start = 0, count = 0, resStart = 0, len = INT_MAX;
        for (int i = 0; i < S.length(); i++) {
            if (expect[S[i]] == 0)
                continue;
                
            found[S[i]]++;
            if (found[S[i]] <= expect[S[i]])
                count++;
            if (count == T.length()) {
                while (expect[S[start]] == 0 || found[S[start]] > expect[S[start]]) {
                    found[S[start]]--;
                    start++;
                }
                if (i - start + 1 < len) {
                    len = i - start + 1;
                    resStart = start;
                }
            }
        }
        if (len == INT_MAX)
            return "";
        return S.substr(resStart, len);
    }
};
