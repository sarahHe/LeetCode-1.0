class Solution {
public:
    int maxProduct(int A[], int n) {
        if (!n) return 0;
        if (n == 1) return A[0];
        
        int global = A[0], local_max = A[0], local_min = A[0];
        for (int i = 1; i < n; i++) {
            int local_copy = local_max;
            local_max = max(max(A[i], local_max * A[i]), A[i] * local_min);
            local_min = min(min(A[i], local_copy * A[i]), A[i] * local_min);
            global = max(global, local_max);
        }
        return global;
    }
};

2015.4.20 update 
reduce run time from 40ms to 11ms
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int global = nums[0], localmin = 1, localmax = 1;
        for (auto i : nums) {
            if (i < 0) //!!!!!
                swap(localmin, localmax);
                
            localmax = max(i, localmax * i);
            localmin = min(i, localmin * i);
            global = max(global, localmax);
        }
        return global;
    }
};
