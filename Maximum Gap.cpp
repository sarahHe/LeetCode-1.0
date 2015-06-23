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
        // int maxNum = *max_element(num.begin(), num.end());
        // int minNum = *min_element(num.begin(), num.end());
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


2015.6.23 update
//no big change
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)    return 0;
        int mins = nums[0], maxs = nums[0];
        for (auto i : nums) {
            mins = min(mins, i);
            maxs = max(maxs, i);
        }
        int gap = ceil((double)(maxs - mins) / (nums.size() - 1)); // must use ceil((double).....)
        vector<int> bucketMin(nums.size() - 1, INT_MAX),
                    bucketMax(nums.size() - 1, INT_MIN);
        for (auto i : nums) {
            if (i == mins || i == maxs) continue;
            int idx = (i - mins) / gap;
            bucketMin[idx] = min(i, bucketMin[idx]);
            bucketMax[idx] = max(i, bucketMax[idx]);
        }
        int maxGap = INT_MIN, previous = mins;
        for (int i = 0; i < nums.size() - 1; i++) { // loop over the bucketMin/bucketMax
            if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN)   continue; //empty bucket
            maxGap = max(maxGap, bucketMin[i] - previous);
            previous = bucketMax[i];
        }
        maxGap = max(maxGap, maxs - previous); // updata the final max value gap
        return maxGap;
    }
};
