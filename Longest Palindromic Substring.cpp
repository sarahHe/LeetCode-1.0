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


2015.5.24 update //reduce from 387ms to 264ms
string longestPalindrome(string s) {
    if (s.size() < 2)   return s;
    
    bool dp[1000][1000] = {false};
    int start = 0, len = 1;
    for (int i = s.length() - 2; i >= 0; --i) {
        for (int j = i + 1; j < s.length(); ++j) {//compare starts from two ends.
            if (s[i] == s[j] && (i + 1 == j - 1 || i + 1 == j || dp[i+1][j-1])) { // i+1==j-1 for even length, i+1==j for odd length
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


//really excelent solution with O(1) space and O(n) time
string longestPalindrome(string s) {
    if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {//increase i later
        if (s.size() - i <= max_len / 2) break;
        int j = i, k = i;
        while (k < s.size()-1 && s[k+1] == s[k])
            ++k; // Skip duplicate characters.
        i = k+1; // for next time i shoud increase by 1
        
        while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) {
            ++k; --j;
        } // Expand.

        if (k - j + 1 > max_len) {
            min_start = j;
            max_len = k - j + 1;
        }
    }
    return s.substr(min_start, max_len);
}
