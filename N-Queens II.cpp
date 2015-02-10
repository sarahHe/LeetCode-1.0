// Follow up for N-Queens problem.
// Now, instead outputting board configurations, 
// return the total number of distinct solutions.

class Solution {
public:
    bool isValid(vector<int> &A, int cur) {
        for (int i = 0; i < cur; i++) {
            if (A[i] == A[cur] || abs(A[i] - A[cur]) == (cur - i))
                return false;
        }
        return true;
    }

    void placeQueen(vector<int> &A, int cur, int n, int &res) {
        if (cur == n)
            res++;
        else {
            for (int i = 0; i < n; i++) {
                A[cur] = i;
                if (isValid(A, cur))
                    placeQueen(A, cur+1, n, res);
                A[cur] = -1;//although A will have value, 
                //but it won't affect the isValid function.
                //so the A[cur] = -1 is unneccesary.
            }
        }
    }

    int totalNQueens(int n) {
        int res = 0;
        vector<int> A(n, -1);
        placeQueen(A, 0, n, res);
        return res;
    }
};
