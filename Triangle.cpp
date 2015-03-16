// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

// For example, given the following triangle
// [
//      [2],
//     [3,4],
//   [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (!n)   return n;
        if (n == 1) return triangle[0][0];
        
        vector<int> sum(n+1, INT_MAX);
        sum[1] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = triangle[i].size(); j > 0; j--) {
                sum[j] = triangle[i][j-1] + min(sum[j], sum[j-1]);
            }
        }
        int mt = sum[1];
        for (int i = 2; i < n+1; i++)
            mt = min(mt, sum[i]);
        return mt;
    }
};


2015.3.15 update
//can only go down or down right
//buttom up, in-place
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0)
                    triangle[i][j] += triangle[i-1][j];
                
                else if (j == triangle[i].size() - 1)
                    triangle[i][j] += triangle[i-1][j-1];
                else
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < triangle.back().size(); i++)
            res = min(res, triangle.back()[i]);
        return res;
    }
};
