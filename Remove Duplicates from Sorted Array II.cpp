// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array A = [1,1,1,2,2,3],

// Your function should return length = 5, and A is now [1,1,2,2,3].
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i && nums[i] == nums[i - 1]) {
                if (count == 2)  continue;
                else    count++;
            } else  
                count = 1;
            nums[pos++] = nums[i];
        }
        return pos;
    }
};
