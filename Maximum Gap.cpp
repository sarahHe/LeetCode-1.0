class Solution {
//桶排序
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
            return 0;
        
        int maxs = num[0], mins = num[0];
        for (auto i : num) {
            maxs = max(maxs, i);
            mins = min(mins, i);
        }
        int len = (maxs - mins)/num.size() + 1;
        vector<pair<int, int> > bucket((maxs - mins)/len + 1, pair<int, int> (INT_MAX, INT_MIN));
        for (auto i : num) {
            int idx = (i - mins) / len;
            bucket[idx].first = min(i, bucket[idx].first);
            bucket[idx].second = max(i, bucket[idx].second);
        }
        int gap = 0, prev = -1;
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i].first == INT_MAX )
                continue;
            
            if (prev != -1)
                gap = max(gap, bucket[i].first - bucket[prev].second);
            prev = i;
                
        }
        return gap;
    }

};
