// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?
// Would this affect the run-time complexity? How and why?

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            if (nums[low] < nums[high])
                return nums[low];
            
            int mid = low + (high - low)/2;
            if (nums[mid] == nums[high]) {
                low++; high--;
            }
            else if (nums[mid] > nums[high])
                low = mid + 1; // low = mid + 1
            else
                high = mid; // high = mid
        }
        return nums[low];
    }
};
