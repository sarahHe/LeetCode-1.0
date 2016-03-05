//Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
//
//For example, Given s = “eceba”,
//
//T is "ece" which its length is 3.

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> mp;
    int len = 0, count = 0, start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (mp.count(s[i]) == 0)
            count++;
        mp[s[i]]++;
        
        while (count > 2) {
            if (mp[s[start]--] == 0)
                count--;
            
            start++;
        }
        
        if (i - start + 1 > len)
            len = i - start + 1;
    }
    return len;
}
