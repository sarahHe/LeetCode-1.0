class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        res[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            res[i] = res[i-1] * nums[i-1]; //
        }
        int right = 1;
        for (int i = nums.size() - 1; i >=0; i--) { // i = nums.size() -1
            res[i] *= right; // this is before the line below
            right *= nums[i];
        }
        return res;
    }
};
