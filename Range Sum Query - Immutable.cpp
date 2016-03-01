// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3

class NumArray {
private:
    vector<int> sum = {0};
public:
    NumArray(vector<int> &nums) {
        for (auto i : nums)
            sum.push_back(sum.back() + i); // cache the sum when initialization
    }

    int sumRange(int i, int j) {
        return sum[j+1] - sum[i]; // sine we have a 0 at the first, so shift one to the right
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
