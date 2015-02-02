// Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// 从四个边界的'O'出发，它们所能到达的'O'就是没有被包围的'O'。
// 所以，该题可以用BFS遍历或者DFS遍历。
class Solution {
public:
    void BFS(int num, vector<vector<char>> &board) {
        queue<int> q;
        q.push(num);
        board[num/board[0].size()][num%board[0].size()] = 'N';
        while (!q.empty()) {
            int row = q.front() / board[0].size(),
            col = q.front() % board[0].size();
            
            //up
            if (row > 0 && board[row-1][col] == 'O') {
                board[row-1][col] = 'N';
                q.push(q.front() - board[0].size());
            }
            //right
            if (col < board[0].size() - 1 && board[row][col+1] == 'O') {
                board[row][col+1] = 'N';
                q.push(q.front()+1);
            }
            //bottom
            if (row < board.size() - 1 && board[row+1][col] == 'O') {
                board[row+1][col] = 'N';
                q.push(q.front()+board[0].size());
            }
            //left
            if (col > 0 && board[row][col-1] == 'O') {
                board[row][col-1] = 'N';
                q.push(q.front() - 1);
            }
            q.pop();
        }
    }

    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty())
            return;
        //up, bottom
        for (int i=0; i<(int)board[0].size(); i++) {
            if (board[0][i] == 'O')
                BFS(i, board);
            if (board[board.size()-1][i] == 'O')
                BFS((board.size()-1) * board[0].size() + i, board);
        }
        //right, left
        for (int i=0; i<(int)board.size(); i++) {
            if (board[i][board[0].size()-1] == 'O')
                BFS((i+1)*board[0].size() - 1, board);
            if (board[i][0] == 'O')
                BFS(i*board[0].size(), board);
        }
        
        //flip
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'N')
                    board[i][j] = 'O';
            }
        }
    }
};
