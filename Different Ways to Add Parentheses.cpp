// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


// Example 1
// Input: "2-1-1".

// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]


// Example 2
// Input: "2*3-4*5"

// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10]

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            if (isdigit(input[i]))  continue;
            
            vector<int> res1 = diffWaysToCompute(input.substr(0, i));
            vector<int> res2 = diffWaysToCompute(input.substr(i+1));
            
            for (auto r1 : res1) {
                for (auto r2 : res2) {
                    if (input[i] == '+')
                        res.push_back(r1 + r2);
                    else if (input[i] == '-')
                        res.push_back(r1 - r2);
                    else
                        res.push_back(r1 * r2);
                }
            }
        }
        if (res.empty())
                res.push_back(atoi(input.c_str()));
        return res;
    }
};
