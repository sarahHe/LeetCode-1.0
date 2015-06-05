class Solution {
public:
    bool cycleFound(vector<bool> &checked, int course, set<int> &s, vector<vector<int>> &mp) {
        checked[course] = true;
        s.insert(course);
        for (auto pre : mp[course]) {
            if (s.count(pre) || cycleFound(checked, pre, s, mp))
                return true;
        }
        s.erase(course);
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> mp(numCourses);
        vector<bool> checked(numCourses);
        set<int> s;
        for(auto i : prerequisites)
            mp[i.first].push_back(i.second);
        for (int i = 0; i < mp.size(); i++) {
            if (checked[i]) continue;
            if (cycleFound(checked, i, s, mp))
                return false;
        }
        return true;
    }
};
