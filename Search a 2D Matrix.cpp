class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (target < matrix[0][0] || target > matrix.back().back())
            return false;
        int i = 0;
        for (; i < matrix.size(); i++) {
            if (matrix[i][0] >= target)
                break;
        }
        
        if (i != matrix.size() && matrix[i][0] == target)
            return true;
            
        int low = 0, high = matrix[i - 1].size();
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (matrix[i - 1][mid] == target)
                return true;
            else if (matrix[i - 1][mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
