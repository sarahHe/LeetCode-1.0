class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        while (i < matrix.size() && matrix[i][0] <= target)
            i++;
        if (i == 0)
            return matrix[0][0] == target;
        for (int j = 0; j < matrix[i-1].size(); j++)
            if (matrix[i-1][j] == target)
                return true;
        return false;
    }
};
