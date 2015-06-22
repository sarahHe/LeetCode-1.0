// Given a string S and a string T, count the number of distinct subsequences of T in S.
// A subsequence of a string is a new string which is formed from 
// the original string by deleting some (can be none) of the 
// characters without disturbing the relative positions of the 
// remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
// Here is an example:
// S = "rabbbit", T = "rabbit"
// Return 3.

// 此题需要使用大数运算。使用一点 DP 即可。关键是如何得到递推关系，可以这样想，设母串的长度为 j，  
// 子串的长度为 i，我们要求的就是长度为 i 的字串在长度为 j 的母串中出现的次数，设为 t[i][j]，若母串的最后一个字符与子串的最后一个字符不同，则长度为 i 的子串在长度为 j 的母串中出现的次数就是母串的前 j - 1 个字符中子串出现的次数，即 t[i][j] = t[i][j - 1]，若母串的最后一个字符与子串的最后一个字符相同，那么除了前 j - 1 个字符出现字串的次数外，还要加上子串的前 i - 1 个字符在母串的前 j - 1 个字符中出现的次数，即 t[i][j] = t[i][j - 1] + t[i - 1][j]。  
class Solution {
public:
    int numDistinct(string S, string T) {
        if (S.length() < T.length())
            return 0;
        vector<int> dp(T.length()+1, 0);
        dp[0] = 1;
        for (int i = 0; i < S.length(); i++) {
            for (int j = T.length() - 1; j >= 0; j--) {// j应该从尾到头，因为每次要使用上一次loop的值。如果从头往尾扫的话，重复计算了。
                if (S[i] == T[j])
                    dp[j+1] += dp[j]; 
            }
        }
        return dp.back();
    }
};



2015.6.21 update
class Solution {
// Path[i][j] = Path[i][j-1]            (discard S[j])
//              +     Path[i-1][j-1]    (S[j] == T[i] and we are going to use S[j])
//                 or 0                 (S[j] != T[i] so we could not use S[j])
// while Path[0][j] = 1 and Path[i][0] = 0.
public:
    int numDistinct(string s, string t) {
        if (s.length() < t.length())    return 0;
        
        vector<int> dp(t.length() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {// <=
            // traversing backwards so we are using dp[j-1] from last time step
            for (int j = t.length(); j >= 1; j--)
                dp[j] += s[i-1] == t[j-1] ? dp[j - 1] : 0;
        }
        return dp.back();
    }
};
