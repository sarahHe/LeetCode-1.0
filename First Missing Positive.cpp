// Given an unsorted integer array, find the first missing positive integer.
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
// Your algorithm should run in O(n) time and uses constant space.

// 第一步，遍历数组，如果A[i]不等于i+1，也就是相应数字没有出现在该出现的位置上，
// 则交换A[i]和A[A[i] - 1]，直到A[i]<=0或者A[i]>N或者A[i]==i+1为止。
// 第二步，遍历数组，第一个满足A[i] != i+1的i，First missing positive为i+1。

//return the first missin integer start from 1
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for (int i = 0; i < n; i++) {
            while(A[i] != i+1) {
                if (A[i] <= 0 || A[i] > n || A[i] == A[ A[i] - 1])
                    break;
                    
                swap(A[i], A[ A[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (A[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};
