//there might be duplicates in L
class Solution {
public:
    bool found(string S, int pos, int wordSize, int wordNum, unordered_map<string, int> &wordCount) {
        unordered_map<string, int> foundCount;
        for (int i = 0; i < wordNum; i++) {
            string cur = S.substr(pos+i*wordSize, wordSize);
            if (wordCount[cur] == 0)
                return false;
                
            foundCount[cur]++;
            if (foundCount[cur] > wordCount[cur])
                return false;
        }
        return true;
    }
    
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0 || L[0].size() == 0 || S.length() < L[0].size() * L.size())
            return res;
            
        unordered_map<string, int> wordCount;
        for (auto i : L)
            wordCount[i]++;
        for (int i = 0; i <= S.length() - L[0].size() * L.size(); i++) {
            if (found(S, i, L[0].size(), L.size(), wordCount))
                res.push_back(i);
        }
        return res;
    }
};
