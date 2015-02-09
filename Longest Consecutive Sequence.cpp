// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

//store in hash_set and use dp
//search for number until all possible numbers exhaust
//once count erase
//once erased, continue next loop
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hs;
        for (int i = 0; i < num.size(); i++)
            hs.insert(num[i]);
            
        int res = 0;
        for (int i = 0; i < num.size(); i++) {
            int tmp = num[i], count = 1;
            if (hs.find(tmp) == hs.end())
                continue;
                
            hs.erase(tmp);
            while (hs.find(++tmp) != hs.end()) {
                count++;
                hs.erase(tmp);
            }
            tmp = num[i];
            while (hs.find(--tmp) != hs.end()) {
                count++;
                hs.erase(tmp);
            }
            res = max(res, count);
        }
        return res;
    }
};
