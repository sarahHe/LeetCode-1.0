class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (dict.empty())   return 0;
    
        queue<string> matched;
        matched.push(start);
        unordered_map<string, int>   step_map;
        step_map[start] = 1;
    
        while (!matched.empty()) {
            string str = matched.front();
            matched.pop();
            for (int i = 0; i < str.length(); i++) {
                string copy_str = str;
                for (char j = 'a'; j <= 'z'; j++) {
                    if (copy_str[i] == j)    continue;
                    
                    copy_str.replace(i, 1, 1, j);
                    if (copy_str == end)
                        return step_map[str] + 1;
                    
                    if (dict.find(copy_str) != dict.end() && !step_map[copy_str]) {
                        matched.push(copy_str);
                        step_map[copy_str] = step_map[str] + 1;
                    }
                    
                }
            }
        }
        return 0;
    }
};
