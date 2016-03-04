//The idea is similar to the problem Paint House I, for each house and each color, the minimum cost of painting the house with that color should be the minimum cost of painting previous houses, and make sure the previous house doesn't paint with the same color.
//
//We can use min1 and min2 to track the indices of the 1st and 2nd smallest cost till previous house, if the current color's index is same as min1, then we have to go with min2, otherwise we can safely go with min1.
int minCostII(vector<vector<int>> &costs) {
    int min1 = -1, min2 = -1;
    for (int i = 0; i < costs.size(); i++) {
        int last1 = min1, last2 = min2;
        for (int j = 0; j < costs[0].size(); j++) {
            if (j != last1)
                costs[i][j] = last1 < 0 ? 0 : costs[i-1][last1];
            else
                costs[i][j] = last2 < 0 ? 0 : costs[i-1][last2];
            
            if (min1 < 0 || costs[i][j] < costs[i][min1]) {
                min2 = min1;
                min1 = j;
            }
            else if (min2 < 0 || costs[i][j] < costs[i][min2])
                min2 = j;
        }
    }
    return costs.back()[min1];
}
