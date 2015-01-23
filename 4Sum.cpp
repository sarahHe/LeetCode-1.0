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
