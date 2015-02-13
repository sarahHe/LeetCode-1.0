// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

class Solution {
// 其实这个问题可以转化为Largest Rectangle in Histogram
// 然后对每一行求最大矩形面积
public:
    int getMaxRectangle(vector<int> &height) {
        height.push_back(0);
        stack<int> s;
        int area = 0;
        for (int i = 0; i < height.size(); i++) {
            if (s.empty() || (!s.empty() && height[s.top()] <= height[i]))
                s.push(i);
            else {
                while (!s.empty() && (height[s.top()] > height[i])) {
                    int idx = s.top();
                    s.pop();
                    int width = s.empty() ? i : i - s.top() - 1;
                    area = max(area, width * height[idx]);
                }
                s.push(i);//important
            }
            
        }
        return area;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
         if (matrix.size() == 0 || matrix[0].size() == 0)
            return 0;
            
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp (m, vector<int> (n, 0));
        for (int i = 0; i < n; i++)
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
        
        //transfer to histogram problem
        for (int j = 0; j < n; j++) { // col
            for (int i = 1; i < m; i++) { // row
                if (matrix[i][j] == '1')
                    dp[i][j] = dp[i-1][j] + 1;
            }
        }
        
        int area = 0;
        //get the max area for each level of histogram
        for (int i = 0; i < m; i++) {
            int local = getMaxRectangle(dp[i]);
            area = max(area, local);
        }
        return area;
    }
};
