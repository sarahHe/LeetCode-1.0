// Given a collection of numbers that might contain duplicates, 
// return all possible unique permutations.
// For example,
// [1,1,2] have the following unique permutations:
// [1,1,2], [1,2,1], and [2,1,1].

// 至此我们已经运用了递归与非递归的方法解决了全排列问题，总结一下就是：
// 1．全排列就是从第一个数字起每个数分别与它后面的数字交换。
// 2．去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换。
// 3．全排列的非递归就是由后向前找替换数和替换点，然后由后向前找
// 第一个比替换数大的数与替换数交换，最后颠倒替换点后的所有数据。

//it turns out that the first method is optimal
class Solution {
public:
    bool noswap(vector<int> &num, int i, int step) {
        for (int j = step; j < i; j++) {
            if (num[i] == num[j])
                return true;
        }
        return false;
    }
    void dfs(vector<int> &num, int step, vector<vector<int> > &res) {
        if (step == num.size()) {
            res.push_back(num);
            return;
        }
        for (int i = step; i < num.size(); i++) {
            if (noswap(num, i, step))//实在不明白为什么这一句就可以
            // if (num[i] == num[step])//这一句就不行
                continue;
            swap(num[i], num[step]);
            dfs(num, step + 1, res);
            swap(num[i], num[step]);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        dfs(num, 0, res);
        return res;
    }
};



2015.5.17 update
//!!don't understand: pass by value and not swap back. 
class Solution {
public:
    void helper(vector<int> nums, vector<vector<int>> &res, int pos) {
        if (pos == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            if (i != pos && nums[i] == nums[pos]) continue;
            swap(nums[i], nums[pos]);
            helper(nums, res, pos+1); //why not swap back and pass by value
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())   return vector<vector<int>>();
        
        sort(nums.begin(), nums.end()); //why sort
        vector<vector<int>> res;
        helper(nums, res, 0);
        return res;
    }
};



//using map grouping same value
class Solution {
public:
    void helper(vector<int>& tmp, vector<vector<int>> &res, unordered_map<int, int> &mp, int n) {
        if (n == 0) {
            res.push_back(tmp);
            return;
        }
        
        for (auto &i : mp) {// &i not i
            if (i.second == 0) continue;
            tmp.push_back(i.first);
            i.second--; // because i.second needs to be modified
            helper(tmp, res, mp, n-1);
            tmp.pop_back();
            i.second++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty())   return vector<vector<int>>();
        
        vector<vector<int>> res;
        unordered_map<int, int> mp; // (number, times)
        for (auto i : nums) {
            if (mp[i])
                mp[i]++;
            else
                mp[i] = 1;
        }
        
        vector<int> tmp;
        helper(tmp, res, mp, nums.size());
        return res;
    }
};
