class Solution {
public:
    bool canJump(int A[], int n) {
        if (n <= 1) return true;
        
        int max_jump = A[0], cur = 1;
        while (cur < n && max_jump >= cur) {
            if (cur + A[cur] > max_jump)
                max_jump = cur + A[cur];
            cur++;
        }
        return max_jump >= n - 1;
    }
};



2015.5.30 update
class Solution {
public:
//不需要管之前是怎么走到这一格的，反正从这格开始+A[i]所能到达的距离就是local最远
    bool canJump(vector<int>& nums) {
        int i = 0, reach = 0;
        for (; i < nums.size() && i <= reach; i++) { //i <= reach checks for the false case
            reach = max(reach, i + nums[i]);
        }
        return i == nums.size();
    }
};
