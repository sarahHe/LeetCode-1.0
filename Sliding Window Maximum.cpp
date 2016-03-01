// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty() || k <= 0)   return res;
        deque<int> idxDeque; // store index
        for (int i = 0; i < nums.size(); i++) {
            // remove numbers out of range k from front()
            while (!idxDeque.empty() && idxDeque.front() < i - k + 1)
                idxDeque.pop_front();
            // remove numbers less than current number from back
            while (!idxDeque.empty() && nums[idxDeque.back()] < nums[i])
                idxDeque.pop_back();
            
            idxDeque.push_back(i);
            if (i >= k - 1)
                res.push_back(nums[idxDeque.front()]);
        }
        return res;
    }
};
