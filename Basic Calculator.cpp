// Implement a basic calculator to evaluate a simple expression string.

// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .
// You may assume that the given expression is always valid.
// Some examples:
// "1 + 1" = 2
// " 2-1 + 2 " = 3
// "(1+(4+5+2)-3)+(6+8)" = 23

class Solution {
public:
    int calculate(string s) {
        int result = 0, num = 0, sign = 1;
        if (s == "")    return 0;
        
        stack<int> signs; //store signs
        signs.push(sign); // !!
        for (auto i : s) {
            if (isdigit(i)) {
                num = num*10 + (i-'0');
            }
            else if (i == '+' || i =='-') {
                result += num * sign; // handle num before the notation
                sign = signs.top() * (i == '+' ? 1 : -1);
                num = 0;
            }
            else if (i == '(')
                signs.push(sign);
            else if (i == ')') 
                signs.pop();
        }
        result += sign * num;
        return result;
    }
};
