class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < n; i++)
            tmp.push_back(1);
        for (int i = 0; i < n; i++)
            res.push_back(tmp);
        
        if (n == 1) {
            return res;
        }
        
        int k = 1,
        col_low = 0, col_high = n - 1,
        row_low = 0, row_high = n - 1;
        while (col_low < col_high) {
            //up
            for (int i = col_low; i < col_high; i++)
                res[row_low][i] = k++;
            //right
            for (int i = row_low; i < row_high; i++)
                res[i][col_high] = k++;
            //bottom
            for (int i = col_high; i > col_low; i--)
                res[row_high][i] = k++;
            //left
            for (int i = row_high; i > row_low; i--)
                res[i][col_low] = k++;
            col_low++, col_high--, row_low++, row_high--;
        }
        if (col_low == col_high)
            res[row_low][col_low] = k;
        return res;
    }
};
