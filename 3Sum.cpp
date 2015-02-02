// Given an array S of n integers, are there elements a, b, c 
// in S such that a + b + c = 0? Find all unique triplets 
// in the array which gives the sum of zero.

//固定一个 动态两个
//注意去重复的
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        if (num.size() < 3)    return res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size()-2; i++) {
            if (i > 0 && num[i] == num[i-1])
                continue;
                
            int low = i+1, high = num.size()-1;
            while (low < high) {
                if (num[i] + num[low] + num[high] == 0) {
                    vector<int> tmp = {num[i], num[low], num[high]};
                    res.push_back(tmp);
                    low++;
                    high--;
                }
                else if (num[i] + num[low] + num[high] < 0)
                    low++;
                else
                    high--;
                while (low > i+1 && num[low] == num[low-1])
                    low++;
                while (high < num.size()-1 && num[high] == num[high+1])
                    high--;
            }
        }
    }
};
