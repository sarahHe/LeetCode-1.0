// Given two integers representing the numerator and 
// denominator of a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part in parentheses.
// For example,
// Given numerator = 1, denominator = 2, return "0.5".
// Given numerator = 2, denominator = 1, return "2".
// Given numerator = 2, denominator = 3, return "0.(6)".

// 1、负数的处理
// 2、INT_MIN的处理，将 INT_MIN转化为正数会溢出，因此要使用long long int来计算。
// 3、分为整数部分和小数部分，重点在于小数部分的处理，因为小数部分有可能会出现循环。
// 当余数为4时，将出现循环，所以我们可以设置一个哈希表，
// 存储每一次的余数，以及该余数在返回结果result中的下标。
// 每一次得到新的余数，就查询该余数是否已经在哈希表中，
// 是的话说明开始循环了，那么直接在result中该余数对应的位置后面插入
// ‘（’，result末尾加上‘）’，结束运算。如果在哈希表中没找到，则继续正常运运算。
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string result;
        if(numerator < 0 ^ denominator < 0 )
            result += '-';   //异或，numerator<0和denominator<0仅有一个为真
        //转化为正数，INT_MIN转化为正数会溢出，故用long long。
        //long long int n=abs(INT_MIN)得到的n仍然是负的，所以写成下面的形式。
        long long int n = numerator,
                      d = denominator; 
        n = abs(n); d = abs(d);
        //or use fabs instead of abs, which return int
        // code:
        //long long a = fabs(numerator), b = fabs(denominator);
        result += to_string(n / d);  //整数部分
        long long int r = n % d;	//余数r
        if (r == 0)
            return result;
        else
            result += '.';
        //下面处理小数部分，用哈希表
        unordered_map<long long, unsigned long> map;
        while (r){
            //检查余数r是否在哈希表中，是的话则开始循环了
            if (map[r]){
                result.insert(map[r], 1, '(');   
                //http://www.cplusplus.com/reference/string/basic_string/insert/
                result += ')';
                break;
            }
            map[r] = result.size();	//这个余数对应于result的哪个位置
            //正常运算
            r *= 10;
            result += to_string(r / d);
            r = r % d;
        }
        return result;
    }
};
