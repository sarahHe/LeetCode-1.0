class Solution {
public:
    bool valid(vector<vector<char> > &board, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == board[row][col] && i != col)   return false;
            if (board[i][col] == board[row][col] && i != row)   return false;
        }
        
        int r = row/3*3, c = col/3*3;
        for (int i = r; i < r+3; i++) {
            for (int j = c; j < c+3; j++) {
                if (board[i][j] == board[row][col] && (i != row || j != col))
                    return false;
            }
        }
        return true;
    }

    bool solveHelper(vector<vector<char> > &board, int row, int col) {
        if (row == 9)
            return true;
        
        int row2, col2;
        if (col == 8) {
            row2 = row+1;
            col2 = 0;
        }
        else {
            row2 = row;
            col2 = col+1;
        }
        if (board[row][col] != '.') {
            if (!valid(board, row, col))   return false;
            else
                return solveHelper(board, row2, col2);
        }
        for (int i = 1; i < 10; i++) {
            board[row][col] = i + '0';
            if (valid(board, row, col) && solveHelper(board, row2, col2))   
                return true;    
        }
        board[row][col] = '.';
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        solveHelper(board, 0 , 0);
    }
};
