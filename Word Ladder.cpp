class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if (wordDict.empty())   return 0;
        
        queue<string> q;
        unordered_map<string, int> step_map;
        step_map[beginWord] = 1;
        q.push(beginWord);
        
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (int i = 0; i < cur.length(); i++) {
                string copy_cur = cur; //!!
                for (char j = 'a'; j <= 'z'; j++) {
                    if (j == cur[i])    continue; //!!
                    
                    copy_cur.replace(i, 1, 1, j); //replace(pos, len, times, new_str), change the string
                    if (copy_cur == endWord)
                        return step_map[cur] + 1;
                    
                    if (wordDict.find(copy_cur) != wordDict.end() && !step_map[copy_cur]) {
                        //if in the dict and not in step_map(to get smallest steps)
                        step_map[copy_cur] = step_map[cur] + 1;
                        q.push(copy_cur);
                    }
                }
            }
        }
        return 0;
    }
};
