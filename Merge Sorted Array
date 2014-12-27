class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        if (n == 0) return;
        
        int k = m + n - 1, i = m - 1, j = n - 1;
        while (i >=0 && j >= 0) {
            A[k--] = A[i] > B[j] ? A[i--] : B[j--];
        }
        if (i < 0) {
            while (j >= 0) 
                A[k--] = B[j--];
        }
        else if (j < 0) {
            while (i >= 0)
                A[k--] = A[i--];
        }
    
    }
};
