// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, 
// where "adjacent" cells are those horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// For example,
// Given board =

// [
//   ["ABCE"],
//   ["SFCS"],
//   ["ADEE"]
// ]
// word = "ABCCED", -> returns true,
// word = "SEE", -> returns true,
// word = "ABCB", -> returns false.


//不一定要一次性检验完成，可以一次不对再看下一个，对了就直接返回
class Solution {
public:
    bool findPath(vector<vector<char> > &board, string word, int num, int idx) {
        if (idx == word.length()) return true;
        
        int dx[4] = {-1, 0, 0, 1}; //巧妙
        int dy[4] = {0, -1, 1, 0};
        for (int i = 0; i < 4; i++) {
            int row = (int)num / board[0].size() + dx[i], //!!
            col = (int)num % board[0].size() + dy[i];
            if (row >= 0 && row < board.size() &&
                col >= 0 && col < board[0].size() &&
                board[row][col] == word[idx]) {
                board[row][col] = '#';
                if (findPath(board, word, row*board[0].size() + col, idx+1)) {
                    board[row][col] = word[idx];
                    return true;
                }
                board[row][col] = word[idx];
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size()*board[0].size() < word.length()
            || word == "")      return false;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '#';
                    if (findPath(board, word, i*board[0].size()+j, 1))
                        return true;
                    board[i][j] = word[0]; //记得改回来
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool find(vector<vector<char> > &board, string word, int row, int col, int pos) {
        if (pos == word.length())   return true;
        
        if (row > 0 && board[row-1][col] == word[pos]) {
            board[row-1][col] = '#';
            if (find(board, word, row - 1, col, pos+1)) {
                board[row-1][col] = word[pos];
                return true;
            }
            board[row-1][col] = word[pos];
        }
        if (row < board.size() - 1 && board[row+1][col] == word[pos]) {
            board[row+1][col] = '#';
            if (find(board, word, row + 1, col, pos+1)) {
                board[row+1][col] = word[pos];
                return true;
            }
            board[row+1][col] = word[pos];
        }
        if (col > 0 && board[row][col-1] == word[pos]) {
            board[row][col - 1] = '#';
            if (find(board, word, row, col - 1, pos + 1)) {
                board[row][col - 1] = word[pos];
                return true;
            }
            board[row][col - 1] = word[pos];
        }
        if (col < board[0].size() - 1 && board[row][col + 1] == word[pos]) {
            board[row][col+1] = '#';
            if (find(board, word, row, col+1, pos+1)) {
                board[row][col+1] = word[pos];
                return true;
            }
            board[row][col+1] = word[pos];
        }
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        if (word == "") return true;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0])
                    continue;
                
                board[i][j] = '#';
                if (find(board, word, i, j, 1)) 
                    return true;
                board[i][j] = word[0];
            }
        }
        return false;
    }
};
