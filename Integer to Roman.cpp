// Given an integer, convert it to a roman numeral.
// Input is guaranteed to be within the range from 1 to 3999.

// I = 1;
// V = 5;
// X = 10;
// L = 50;
// C = 100;
// D = 500;
// M = 1000;

// 采用贪心策略，每次选择能表示的最大的值，把对应的字符串连接起来，代码及其简洁

class Solution {
public:
    string intToRoman(int num) {
        vector<string> str = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        vector<int> val = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string res = "";
        for (int i=0; i<str.size(); i++) {
            while (num >= val[i]) {
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};
