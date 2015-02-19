class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() != 9 || board[0].size() != 9)
            return false;
        
        //check row
        for (int i = 0; i < 9; i++) {
             vector<bool> used (9, false);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int k = board[i][j] - '0';
                if (board[i][j] == 0 || used[k-1])
                    return false;
                used[k-1] = true;
            }
        }
        //check col
        for (int j = 0; j < 9; j++) {
             vector<bool> used (9, false);
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                int k = board[i][j] - '0';
                if (board[i][j] == 0 || used[k-1])
                    return false;
                used[k-1] = true;
            }
        }
        
        //check subbox
        for (int i = 0; i < 9; i += 3) {//col
            for (int j = 0; j < 9; j += 3) {
                 vector<bool> used (9, false);
                for (int p = 0; p < 3; p++) {
                    for (int q = 0; q < 3; q++) {
                        if (board[i+p][j+q] == '.')
                            continue;
                        int k = board[i+p][j+q] - '0';
                        if (k == 0 || used[k-1])
                            return false;
                        used[k-1] = true;
                    }
                }
            }
        }
        return true;
    }
};
