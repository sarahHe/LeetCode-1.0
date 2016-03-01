// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
// You may assume that the given expression is always valid.
// Some examples:
// "3+2*2" = 7
// " 3/2 " = 1
// " 3+5 / 2 " = 5

class Solution {
public:
    int calculate(string s) {
        if (s == "")    return 0;
        
        stack<int> nums;
        int num = 0;
        char sign = '+';
        for (int i =0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                num = num*10 + s[i]-'0';
            } 
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) { // don't forget the last char 
                switch (sign) {
                    case '+': nums.push(num);break;
                    case '-': nums.push(-num);break;
                    case '*': {
                        int top = nums.top();
                        nums.pop();
                        nums.push(top * num);
                        break;
                    }
                    case '/': {
                        int top = nums.top();
                        nums.pop();
                        nums.push(top / num);
                        break;
                    }
                    default: break;
                }
                sign = s[i];    
                num = 0;
            }
        }
        
        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};
