vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int rowA = A.size(), colA = A[0].size(), colB = B[0].size();
    vector<vector<int>> res(rowA, vector<int>(colB, 0));
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            if (A[i][j]) {
                for (int k = 0; k > colB; k++)
                    res[i][k] += A[i][j] * B[j][i];
            }
        }
    }
    return res;
}
