// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

class Solution {
public:
    void exploreIsland(vector<vector<char> > &grid, int i, int j) {
        grid[i][j] = 'X';
        if (i > 0 && grid[i-1][j] != 'X' && grid[i-1][j] != '0')
            exploreIsland(grid, i - 1, j);
        if (j < grid[0].size() - 1 && grid[i][j+1] != 'X' && grid[i][j+1] != '0')
            exploreIsland(grid, i, j + 1);
        if (i < grid.size() - 1 && grid[i+1][j] != 'X' && grid[i+1][j] != '0')
            exploreIsland(grid, i + 1, j);
        if (j > 0 && grid[i][j-1] != 'X' && grid[i][j-1] != '0')
            exploreIsland(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty())    return 0;
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 'X' || grid[i][j] == '0')   continue;
                
                exploreIsland(grid, i, j);
                count++;
            }
        }
        return count;
    }
};
