// Given a list of non negative integers, arrange them such that they form the largest number.
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
// Note: The result may be very large, so you need to return a string instead of an integer.

// 关键是确定每个数在最后结果中的先后位置，比较直观的是个位数
// 越大的越靠前，如例子中9在5, 4, 3之前；
// 个位相同的再看十位，如例子中34应当在30之前；
// 难点是位数不等时，先后关系怎么确定？如例子中3应当放在
// 30和34之前、之后还是中间？结果是3放在了34和30中间，为什么呢？
// 这是因为十位上的4比个位上3大，所以34在3之前，
// 而十位上的0比个数上的3小，所以30在3之后。
// 这样貌似可以找到规律，就是对于那些有包含关系的数，
// 如1234包含12，那么只需看1234比12多出的部分34比12大还是小。
// 通过这样的方法，貌似也可判断出个先后顺序。
// 只是这样需要考虑的情况太复杂了，如565656和56……

// //正解如下：
// 可以换一下思路，要想比较两个数在最终结果中的先后位置，
// 何不直接比较一下不同组合的结果大小？
// 举个例子：要比较3和34的先后位置，可以比较334和343的大小，
// 而343比334大，所以34应当在前。
// 这样，有了比较两个数的方法，就可以对整个数组进行排序。
// 然后再把排好序的数拼接在一起就好了。

class Solution {
public:
    struct CMP {
        bool operator()(int n1, int n2) {
            string str1 = to_string(n1), str2 = to_string(n2);
            return str1 + str2 > str2 + str1;
        }
    } cmp;
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        if (nums.empty() || nums[0] == 0)   return "0";
        string res;
        for (auto i : nums)
            res += to_string(i);
        return res;
    }
};
