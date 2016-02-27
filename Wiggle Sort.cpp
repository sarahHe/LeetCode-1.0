//Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

vector<int> wiggleSort(vector<int> &nums) {
    int i = 0;
    for (i = 1; i < nums.size()-1; i += 2) {
        if (nums[i] < nums[i-1])
            swap(nums[i], nums[i-1]);
        if (nums[i] < nums[i+1])
            swap(nums[i], nums[i+1]);
    }
    return res;
}


public void wiggleSort(int[] nums) {
    for(int i = 1; i < nums.length; i++){
        // 需要交换的情况：奇数时nums[i] < nums[i - 1]或偶数时nums[i] > nums[i - 1]
        if((i % 2 == 1 && nums[i] < nums[i-1]) || (i % 2 == 0 && nums[i] > nums[i-1])){
            int tmp = nums[i-1];
            nums[i-1] = nums[i];
            nums[i] = tmp;
        }
    }
}
