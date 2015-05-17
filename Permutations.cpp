class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &tmp, vector<int> &num) {
        if (num.empty())
            res.push_back(tmp);
        else {
            for (int i = 0; i < num.size(); i++) {//变化的不仅是i 还有num.size()
                tmp.push_back(num.front());
                num.erase(num.begin());
                helper(res, tmp, num);
                num.push_back(tmp.back());
                tmp.pop_back();
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> res;
        vector<int> tmp;
        helper(res, tmp, num);
        return res;
    }
};



2015.5.16 update
//it seems swap methos is slower than dfs
class Solution {
public:
    void helper(vector<vector<int>> &res, int pos, vector<int> &nums) {
        if (pos == nums.size()){
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            helper(res, pos + 1, nums);
            swap(nums[pos], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())   return res;
        helper(res, 0, nums);
        return res;
    }
};
