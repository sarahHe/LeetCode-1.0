//Given an array S of n integers, are there elements a, b, c, 
//and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//Note:
//Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
//The solution set must not contain duplicate quadruplets.

//Be careful about the two requirements.
//1. sorted to be non-descending order.
//2. duplicates.
// the way to deal with duplicates is to start from smallest number,
// if it's the same as the previous one, continue.
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.size() < 4) return  res;
        
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 1; i++) {
            if (i > 0 && num[i] == num[i - 1])
                continue;
                
            for (int j = i + 1; j < num.size(); j++) {
                if (j > i + 1 && num[j] == num[j - 1])
                    continue;
                    
                int low = j + 1, high = num.size() - 1;
                while (low < high) {
                    if (num[i] + num[j] + num[low] + num[high] < target)
                        low++;
                    else if (num[i] + num[j] + num[low] + num[high] > target)
                        high--;
                    else {
                        vector<int> tmp = {num[i], num[j], num[low], num[high]};
                        res.push_back(tmp);
                    low++; high--;
                    while (num[low] == num[low - 1])
                        low++;
                    while (num[high] == num[high + 1])
                        high--;
                    }
                }
            }
        }
        return res;
    }
};



2015.5.23 update
class Solution {
public:
    // typedef pair<int, int> PAIR; // store index
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)   return vector<vector<int>>();
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> mp; // sum, pair index
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[i] + nums[j]].push_back(make_pair(i, j));
            }
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1])  continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                
                int sum = target - nums[i] - nums[j];
                if (mp.count(sum) == 0) continue;
                
                for (auto it = mp[sum].begin(); it != mp[sum].end(); it++) {
                    int idx1 = (*it).first, idx2 = (*it).second;
                    if (idx1 <= j)    continue;// idx1>j make sure that the third pair has bigger values than the previous pair.
                    
                    if (!res.empty() && nums[i] == res.back()[0] && nums[j] == res.back()[1] && nums[idx1] == res.back()[2] && nums[idx2] == res.back()[3])
                        continue;
                    
                    vector<int> tmp = {nums[i], nums[j], nums[idx1], nums[idx2]};
                    res.push_back(tmp);
                }
            }
        }
        
        return res;
    }
};
