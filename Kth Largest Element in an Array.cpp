// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while (true) {
            int pos = partition(left, right, nums);
            if (pos == k - 1)   return nums[pos];
            if (pos < k - 1)
                left = pos+1;
            else
                right = pos-1;
        }
    }
    
    int partition(int left, int right, vector<int> &nums) {
        int pivot = nums[left];
        int l = left+1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && pivot < nums[r]) 
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot)    l++;
            if (nums[r] <= pivot)    r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};
