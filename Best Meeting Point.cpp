//A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
//
//For example, given three people living at (0,0), (0,4), and (2,2):
//
//1 - 0 - 0 - 0 - 1
//|   |   |   |   |
//0 - 0 - 0 - 0 - 0
//|   |   |   |   |
//0 - 0 - 1 - 0 - 0
//The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.
//
//Hint:
//
//Try to solve it in one dimension first. How can this solution apply to the two dimension case?
//Since the distance is computed using the Manhattan Distance, we can decompose this 2-d problem into two 1-d problems and combine (add) their solutions. In fact, the best meeting point is just the point that comprised by the two best meeting points in each dimension.
//
//For the 1d case, the best meeting point is just the median point.

int getMedianPoint(vector<int> &v) {
    int i = 0, j = v.size() - 1;
    int res = 0;
    while (i < j)
        res += v[j--] - v[i++];
    return res;
}

int minTotalDistance(vector<vector<int>>& grid) {
    vector<int> X, Y;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j]) {
                X[i] = i;
                Y[j] = j;
            }
        }
    }
    return getMedianPoint(X) + getMedianPoint(Y);
}
