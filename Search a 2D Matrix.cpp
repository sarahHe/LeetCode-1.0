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



2016.2.27
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //binary search
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = n * m - 1;
        while (left < right) {
            int mid = (left+right)/2;
            if (matrix[mid/m][mid%m] == target)
                return true;
            if (matrix[mid/m][mid%m] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return matrix[left/m][left%m] == target;
    }
};
