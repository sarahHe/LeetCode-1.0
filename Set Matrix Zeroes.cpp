//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place. 
//O(1)space
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
            
        // store for row_zero and col_zero    
        bool fst_row = false, fst_col = false;
        for (int i = 0; i < (int)matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                fst_col = true;
                break;
            }
        }
        for (int i = 0; i < (int)matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                fst_row = true;
                break;
            }
        }
        
        for (int i = 0; i < (int)matrix.size(); i++) {
            for (int j = 0; j < (int)matrix[0].size(); j++) {
                if (matrix[i][j] == 0) { // the most important part
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < (int)matrix.size(); i++) { //start from 1
            for (int j = 1; j < (int)matrix[0].size(); j++) { //start from 1
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        
        if (fst_row) {
            for (int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        }
        if (fst_col) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        }
    }
};
