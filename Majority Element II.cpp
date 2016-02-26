// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

// Hint:
// How many majority elements could it possibly have? (3-1)


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())   return res;
        
        int count1 = 0, count2 = 0, candidate1 = 0, candidate2 = 1;
        for (auto i : nums) {
            if (i == candidate1)
                count1++;
            else if (i == candidate2)
                count2++;
            else if (count1 == 0) {
                candidate1 = i;
                count1++;
            }
            else if (count2 == 0) {
                candidate2 = i;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for (auto i : nums) {
            if (i == candidate1)
                count1++;
            if (i == candidate2)
                count2++;
        }
        if (count1 > nums.size() / 3)   res.push_back(candidate1);
        if (count2 > nums.size() / 3)   res.push_back(candidate2);
        return res;
    }
};
