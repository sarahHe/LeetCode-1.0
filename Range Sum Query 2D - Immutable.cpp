//Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by 
//its upper left corner (row1, col1) and lower right corner (row2, col2).

class NumMatrix {
    int row, col;
    vector<vector<int>> sum;
    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        row = matrix.size();
        col = row > 0 ? matrix[0].size() : 0; // corner case
        sum = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        // sums[i+1][j+1] represents the sum of area from matrix[0][0] to matrix[i][j]
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++)
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i-1][j-1];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row2+1][col1] - sum[row1][col2+1] + sum[row1][col1]; // be careful of the indexes
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
