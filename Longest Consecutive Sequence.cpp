// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

//store in hash_set and use dp
//search for number until all possible numbers exhaust
//once count erase
//once erased, continue next loop
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> hs;
        int res = 0;
        for (auto i : num)
            hs.insert(i);
        
        int i = 0;  
        while (i < num.size() && !hs.empty()) { // check hs.empty() speed up the program
            int tmp = num[i], count = 1;
            if (hs.find(tmp) == hs.end()) {
                i++;
                continue;
            }
            
            hs.erase(tmp);
            while (!hs.empty() && hs.find(++tmp) != hs.end()) {
                hs.erase(tmp);
                count++;
            }
            
            tmp = num[i];
            while (!hs.empty() && hs.find(--tmp) != hs.end()) {
                hs.erase(tmp);
                count++;
            }
            res = max(res, count);
            i++;
        }
        return res;
    }
};



2015.6.4 update
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int len = 0;
        for (int i : nums) {
            if (mp[i])    continue;
            
            int left = mp[i-1], right = mp[i+1],
                sum = left + right + 1;
            len = max(len, sum);
            mp[i] = sum;
            mp[i-left] = sum;
            mp[i+right] = sum;
        }
        return len;
    }
};
