class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // bool flag = true;
        int i = (int)digits.size() - 1;
        while (i >= 0) {
            if (digits[i] != 9)
                break;
            i--;
        }
        if (i == -1) {
            digits[0] = 1;
            for (int j = 1; j < (int)digits.size(); j ++)
                digits[j] = 0;
            digits.push_back(0);
            
        }
        else {  
            for (int i = (int)digits.size() - 1; i >= 0; i--) {
                if (digits[i] == 9) 
                    digits[i] = 0;
                else {
                    digits[i] += 1;
                    break;
                }
            }
        }
        return digits;
    }
};


2015.3.1 update
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int next = 1;
        for (int i = digits.size()-1; i >= 0; i--) {
            if (digits[i] + next == 10) {
                digits[i] = 0;
                next = 1;
            }
            else {
                digits[i] += next;
                next = 0;
                break;
            }
        }
        vector<int> res;
        if (next)
            res.push_back(1);
        for (int i =0; i < digits.size(); i++)
            res.push_back(digits[i]);
        return res;
    }
};
