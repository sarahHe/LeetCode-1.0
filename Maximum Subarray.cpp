class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (!n) return 0;
        
        int local = A[0], global = A[0];
        for (int i = 1; i < n; i++) {
            local = max(A[i], local + A[i]);
            global = max(local, global);
        }
        return global;
    }
};


2015.5.24 update
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, 0); //reset if sum < 0
        }
        return res;
    }
};
