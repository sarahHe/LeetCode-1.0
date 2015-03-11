// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array A = [1,1,1,2,2,3],

// Your function should return length = 5, and A is now [1,1,2,2,3].
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n < 1)  return 0;
        int count = 1, pos = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i-1]) {
                count++;
                if (count <= 2) 
                    A[pos++] = A[i];
            }
            else {
                A[pos++] = A[i];
                count = 1; // count = 1 not 0
            }
        }
        return pos;
    }
};
