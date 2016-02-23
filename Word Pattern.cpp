class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> s2i;
        istringstream ss(str);
        string word;
        int i = 0;
        for (word; ss >> word; i++) {
            if (i == pattern.size() || p2i[pattern[i]] != s2i[word])
                return false;
            p2i[pattern[i]] = s2i[word] = i+1; // if match, they point to the same index
        }
        return i == pattern.size();
    }
};
