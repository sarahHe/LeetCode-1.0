class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int col_low = 0, col_high = matrix[0].size() - 1, 
            row_low = 0, row_high = matrix.size() - 1;
        while (col_low < col_high && row_low < row_high) {
            for (int i = col_low; i < col_high; i++)
                res.push_back(matrix[row_low][i]);
            
            for (int i = row_low; i < row_high; i++)
                res.push_back(matrix[i][col_high]);
            
            for (int i = col_high; i > col_low; i--)
                res.push_back(matrix[row_high][i]);
            
            for (int i = row_high; i > row_low; i--)
                res.push_back(matrix[i][col_low]);
            
            col_low++, col_high--, row_low++, row_high--;
        }
        //remember the part below
        if (col_low == col_high) {
            for (int i = row_low; i <= row_high; i++)
                res.push_back(matrix[i][col_low]);
        }
        else if (row_low == row_high) {
            for (int i = col_low; i <= col_high; i++)
                res.push_back(matrix[row_low][i]);
        }
        return res;
    }
};
