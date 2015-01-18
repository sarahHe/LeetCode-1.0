/*
Given a string, find the length of the longest substring 
without repeating characters. For example, the longest substring 
without repeating letters for "abcabcbb" is "abc", 
which the length is 3. For "bbbbb" the longest substring is "b", 
with the length of 1.

There is a case should considered: 
the repeated character could be any position in the substring you found longest. 
Remove all the chars before the first apperance of the repeated one 
and update the repeated on in the hash map

Notice: If erase something unexists, error would arise.

better solution:
不需要存了又erase
对于s[i]：
1.s[i]没有在当前子串中出现过，那么子串的长度加1；
2.s[i]在当前子串中出现过，出现位置的下标为j，那么新子串的起始位置必须大于j，为了使新子串尽可能的长，所以起始位置选为j+1。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, k = 0;
        unordered_map<char, int> unique;
        int clean = 0;
        for (int i = 0; i < s.length(); i++) {
            if (unique[s[i]]) {
                len = max(k, len);
                k = i + 1 - unique[s[i]];
                for (int j = clean; j < unique[s[i]]-1; j++) {
                    unique.erase(s[j]);
                    clean++;
                }
                clean++;
                unique[s[i]] = i+1;
            }
            else {
                unique[s[i]] = i+1;
                k++;
            }
        }
        len = max(k, len);
        return len;
    }
};
