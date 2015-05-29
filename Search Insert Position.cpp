class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {// i <= j
            int m = i + (j - i) / 2;
            if (nums[m] == target)
                return m;
            if (nums[m] > target)
                j = m - 1; // j = m - 1
            else
                i = m + 1; // i = m + 1
        }
        return i;
    }
};
