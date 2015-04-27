// 凡是求最优解的，一般都是走DP的路线。这一题也不例外。首先求dp函数，
// 定义函数
// D[i,n] = 区间[i,n]之间最小的cut数，n为字符串长度
//  a   b   a   b   b   b   a   b   b   a   b   a
//                      i                      n
// 如果现在求[i,n]之间的最优解？应该是多少？简单看一看，至少有下面一个解
//  a   b   a   b   b   b   a   b   b   a   b   a
//                      i      j   j+1     n
// 此时  D[i,n] = min(D[i, j] + D[j+1,n])  i<=j <n。这是个二维的函数，实际写代码时维护比较麻烦。所以要转换成一维DP。如果每次，从i往右扫描，每找到一个回文就算一次DP的话，就可以转换为
// D[i] = 区间[i,n]之间最小的cut数，n为字符串长度， 则,
// D[i] = min(1+D[j+1], D[i])    i<=j <n
// 有个转移函数之后，一个问题出现了，就是如何判断[i,j]是否是回文？每次都从i到j比较一遍？太浪费了，这里也是一个DP问题。
// 定义函数
// P[i][j] = true if [i,j]为回文
// 那么
// P[i][j] = str[i] == str[j] && P[i+1][j-1];
class Solution {
public:
    int minCut(string s) {
        vector<int> D;//cuts between i and s.length()
        for (int i = 0; i <= s.length(); i++) 
            D.push_back(s.length()-i);
            
        vector<vector<bool> > P (s.length(), vector<bool>(s.length(), false));
        for (int i = s.length()-1; i >= 0; i--) {
            for (int j = i; j < s.length(); j++) {
                if (s[i] == s[j] && (j-i < 2 || P[i+1][j-1])) {
                    P[i][j] = true;
                    D[i] = min(D[i], D[j+1]+1);
                }
            }
        } 
        return D[0]-1;
    }
};



2015.4.26 update reduce from 90ms to 22ms
class Solution {
public:
    int minCut(string s) {
        vector<int> cut(s.length()+1, 0);
        for (int i = 0; i <= s.length(); i++) cut[i] = i-1; //number of cut for first k charactors.
        for (int i = 0; i < s.length(); i++) {
            // odd length palindrome
            for (int j = 0; j <= i && j < s.length() - i && s[i-j] == s[i+j]; j++)
                cut[i+j+1] = min(cut[i-j] + 1, cut[i+j+1]);
            
            // even length palindrome
            for (int j = 1; j <= i+1 && j < s.length() - i && s[i-j+1] == s[i+j]; j++)
                cut[i+j+1] = min(cut[i-j+1]+1, cut[i+j+1]);
        }
        return cut.back();
    }
};
