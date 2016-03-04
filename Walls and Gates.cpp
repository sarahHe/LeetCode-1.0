//You are given a m x n 2D grid initialized with these three possible values.
//
//-1 - A wall or an obstacle.
//0 - A gate.
//INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than2147483647.
//Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
//For example, given the 2D grid:
//
//INF  -1  0  INF
//INF INF INF  -1
//INF  -1 INF  -1
//0  -1 INF INF
//After running your function, the 2D grid should be:
//
//3  -1   0   1
//2   2   1  -1
//1  -1   2  -1
//0  -1   3   4


//BFS
void wallsAndGates(vector<vector<int>> rooms) {
    queue<int> q;
    int n = rooms.size(), m = rooms[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rooms[i][j] == 0)
                q.push(i*m + j);
        }
    }
    
    while (!q.empty()) {
        int r = q.front() / m, c = q.front() % m;
        if (r > 0 && rooms[r-1][c] == INT_MAX) {
            rooms[r-1][c] = rooms[r][c] + 1;
            q.push((r-1) * m + c);
        }
        if (c > 0 && rooms[r][c-1] == INT_MAX) {
            rooms[r][c-1] = rooms[r][c] + 1;
            q.push(r * m + c-1);
        }
        if (r < n-1 && rooms[r+1][c] == INT_MAX) {
            rooms[r+1][c] = rooms[r][c] + 1;
            q.push((r+1) * m + c);
        }
        if (c < m-1 && rooms[r][c+1] == INT_MAX) {
            rooms[r][c+1] = rooms[r][c] + 1;
            q.push(r * m + c+1);
        }
    }
}





class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = m ? rooms[0].size() : 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (!rooms[i][j]) q.push({i, j});
        for (int d = 1; !q.empty(); d++) {
            for (int k = q.size(); k; k--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                add(rooms, q, i - 1, j, m, n, d);
                add(rooms, q, i + 1, j, m, n, d);
                add(rooms, q, i, j - 1, m, n, d);
                add(rooms, q, i, j + 1, m, n, d); 
            }
        }
    }
private:
    void add(vector<vector<int>>& rooms, queue<pair<int, int>>& q, int i, int j, int m, int n, int d) {
        if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] > d) {
            q.push({i, j});
            rooms[i][j] = d;
        }
    }
};
