// Given an array of non-negative integers, you are initially 
// positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// For example:
// Given array A = [2,3,1,1,4]
// The minimum number of jumps to reach the last index is 2. 
// (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

// jump:目前为止的jump数
// lastMax:从A[0]进行jump次jump之后达到的最大范围
// curMax:从0~i这i+1个A元素中能达到的最大范围
// 当lastMax<i，说明jump次已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到
// 记录的curMax。

class Solution {
public:
    int jump(int A[], int n) {
        int local = 0, global = 0, jump=0;
        for (int i = 0; i < n; i++) {
            if (global < i) {
                jump++;
                global = local;
            }
            //change global first
            local = max(local, i + A[i]);
        }
        return jump;
    }
};
