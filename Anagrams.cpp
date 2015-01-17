/*
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

Anagrams: 变位词。只是字母顺序变化了。
先把每个string sort一下 就可以让变位词一模一样了
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string>  res, copy(strs);
        map<string, vector<int>> m;
        for (int i = 0; i < strs.size(); i++) {
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(i);
        }
        for (map<string, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
            if (it->second.size() > 1) {
                for (int i = 0; i < it->second.size(); i++)
                    res.push_back(copy[it->second[i]]);
            }
        }
        return res;
    }
};
