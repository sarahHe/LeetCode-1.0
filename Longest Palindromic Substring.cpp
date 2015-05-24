//Given a string S, find the longest palindromic substring in S. 
//You may assume that the maximum length of S is 1000, 
//and there exists one unique longest palindromic substring. 

//1.肯定是可以暴力法解决
//2.o(N)算法看不懂。。
//3.DP!!
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1)
            return s;
            
        bool isPali[s.length()][s.length()]; //注意这里的初始化方法
        int max = 1, start = 0;
        for (int i = 0; i < s.length(); i++)
            for (int j = 0; j < s.length(); j++) {
                if (i >= j)
                    isPali[i][j] = true;
                else
                    isPali[i][j] = false;
            }
            
        for (int i = 1; i < s.length(); i++) {
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j]) {
                    isPali[j][i] = isPali[j+1][i-1];
                    if (isPali[j][i] && i - j + 1 > max) {
                        start = j;
                        max = i - j + 1;
                    }
                }
                else
                    isPali[j][i] = false;
            }
        }
        return s.substr(start, max);
    }
};


2015.5.24 update
string longestPalindrome(string s) {
    if (s.size() < 2)   return s;
    
    bool dp[1000][1000] = {false};
    int start = 0, len = 1;
    for (int i = s.length() - 2; i >= 0; --i) {
        for (int j = i + 1; j < s.length(); ++j) {
            if (s[i] == s[j] && (i + 1 == j - 1 || i + 1 == j || dp[i+1][j-1])) {
                dp[i][j] = true;
                if (j - i + 1 > len) {
                    len = j - i + 1;
                    start = i;
                }
            }
            
        }
    }
    return s.substr(start, len);
}
