class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0) return vector<vector<int>>();
        
        vector<vector<int>> res(n, vector<int>(n, 0));
        int up = 0, left = 0, down = n -1, right = n - 1;
        int k = 1;
        while (up < down && left < right) {
            for (int j = left; j < right; j++)
                res[up][j] = k++;
            for (int i = up; i < down; i++)
                res[i][right] = k++;
            for (int j = right; j > left; j--)
                res[down][j] = k++;
            for (int i = down; i > up; i--)
                res[i][left] = k++;
            up++; down--; left++; right--;
        }
        if (up == down)
            for (int j = left; j <= right; j++)
                res[up][j] = k++;
        else if (left == right) 
            for (int i = up; i < down; i++)
                res[i][left] = k++;
        return res;
    }
};
