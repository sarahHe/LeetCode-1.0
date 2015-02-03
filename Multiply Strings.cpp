//the code is OK

// Given two numbers represented as strings, 
// return multiplication of the numbers as a string.
// Note: The numbers can be arbitrarily large and are non-negative.
//the number could be large and the result could be large
//so you can't just use int to multiply
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        string res = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        res.append(num1.length() + num2.length(), '0');//very good idea
        for (int i=0; i<num1.length(); i++) {
            int flag = 0, cur;
            for (int j=0; j<num2.length(); j++) {
                cur = res[i+j]-'0' + (num2[j]-'0')*(num1[i]-'0') + flag;//res[i+j] smart
                flag = cur / 10;
                res[i+j] = cur%10 + '0'; //manipulate on the res
            }
            int pos = num1.length();
            while (flag) {
                cur = res[i + pos] - '0' + flag;
                res[i + pos] = cur % 10 + '0';
                flag = cur / 10;
                pos++;
            }
        }
        while (res.length() > 1 && res[res.length()-1] == '0')
            res.resize(res.length()-1);
        reverse(res.begin(), res.end());
        return res;
    }
};
