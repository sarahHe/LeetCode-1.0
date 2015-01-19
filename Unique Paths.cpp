/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?


方法一：
用动态规划我们只需要对所有格子进行扫描一次，
到了最后一个得到的结果就是总的路径数，所以时间复杂度是O(m*n)。
而对于空间可以看出我们每次只需要用到上一行当前列，以及前一列当前行的信息，
我们只需要用一个一维数组存上一行的信息即可，
然后扫过来依次更替掉上一行对应列的信息即可（因为所需要用到的信息都还没被更替掉），
所以空间复杂度是O(n)
*/
public int uniquePaths(int m, int n) {  
    if(m<=0 || n<=0)  
        return 0;  
    int[] res = new int[n];  
    res[0] = 1;  
    for(int i=0;i<m;i++)  
    {  
        for(int j=1;j<n;j++)  
        {  
           res[j] += res[j-1];  
        }  
    }  
    return res[n-1];  
}

方法二：
class Solution {
public:
    void findPath(vector<vector<int> > &v, int m, int n) {
        if (m == 0 || n == 0)
            return;
        if (v[m][n-1] == -1)
            findPath(v, m, n-1);
        if (v[m-1][n] == -1)
            findPath(v, m-1, n);
        v[m][n] = v[m][n-1] + v[m-1][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int> > v(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            v[0][i] = 1;
        for (int i = 0; i < m; i++)
            v[i][0] = 1;
        
        findPath(v, m-1, n-1);
        return v[m-1][n-1];
    }
};
