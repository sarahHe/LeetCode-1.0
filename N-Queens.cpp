// for problem related to board, think about DFS and BFS
// Analysis:
// The classic recursive problem.
// 1. Use a int vector to store the current state, A[i]=j 
//     refers that the ith row and jth column is placed a queen.
// 2. Valid state: not in the same column, which is A[i]!=A[current], 
//     not in the same diagonal direction: abs(A[i]-A[current]) != r-i
// 3. Recursion: 
//     Start: placeQueen(0,n)
//     if current ==n then print result
//     else
//         for each place less than n {
//             place queen
//             if current state is valid, then place next queen place Queen(cur+1,n)
//         }
        
class Solution {
public:
    bool isValid(vector<int> &A, int r) {
        for (int i = 0; i < r; i++) {
            //A[i] == A[r]: same col
            // abs(A[i] - A[r]) == (r - i): same diagonal
            //since cur is the row 0-n, ensure different row
            if (A[i] == A[r] || abs(A[i] - A[r]) == (r - i))
                return false;
        }
        return true;
    }
    
    //cur is the current row
    void placeQueen(vector<int> A, int cur, int n, vector<vector<string> > &res) {
        if (cur == n) {
            vector<string> sltn;
            for (int i = 0; i < n; i++) {
                string tmp(n, '.');
                tmp[A[i]] = 'Q';
                sltn.push_back(tmp);
            }
            res.push_back(sltn);
        } 
        else {
            for (int i = 0; i < n; i++) {
                A[cur] = i;
                if (isValid(A, cur)) //only changed 0-cur
                    placeQueen(A, cur+1, n, res);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> A(n, -1);
        placeQueen(A, 0, n, res);
        return res;
    }
};
