// Given a sorted array of integers, find the starting and ending position of a given target value.
// Your algorithm's runtime complexity must be in the order of O(log n).
// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     //find left most
     vector<int> res(2, -1);
     int i = 0, j = nums.size() - 1;
     while (i < j) {
         int m = i + (j - i)/2;
         if (nums[m] < target)  i = m + 1;
         else   j = m;
     }
     if (nums[i] != target) return res;
     else res[0] = i;

     //find right most
     j = nums.size() - 1; // no need to reset i
     while (i < j) {
         int m = (i + j) /2 + 1;   // Make mid biased to the right
         if (nums[m] > target) j = m - 1;
         else i = m;
     }
     res[1] = j;
     return res;
    }
};
