//Numbers can be regarded as product of its factors. For example, 

//8 = 2 x 2 x 2;
  //= 2 x 4.
//Write a function that takes an integer n and return all possible combinations of its factors. 

//Note: 

//Each combination's factors must be sorted ascending, for example: The factors of 2 and 6 is [2, 6], not [6, 2]. 
//You may assume that n is always positive. 
//Factors should be greater than 1 and less than n.

void helper(vector<vector<int>> &res, vector<int> &tmp, int n, int start) {
    if (n == 1 && tmp.size() > 1) {
        res.push_back(tmp);
        return;
    }
    
    for (int i = start; i <= n; i++) {
        if (n % i == 0) {
            tmp.push_back(i);
            helper(res, tmp, n / i, i);
            tmp.pop_back();
        }
    }
}

vector<vector<int>> getFactors(int n) {
    vector<vector<int>> res;
    vector<int> tmp;
    helper(res, tmp, n, 2);
    return res;
}
