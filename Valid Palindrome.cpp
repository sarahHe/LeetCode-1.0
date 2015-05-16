class Solution {
public:
    bool isPalindrome(string s) {
        if (s.length() == 0) return true;
        
        int m = 0, n = s.length() - 1;
        while(m < n) {
            while (!isalnum(s[m]) && m < n)
                m++;
            if (m >= n)
                return true;
    
            while (!isalnum(s[n]) && m < n)
                n--;
            if (m >= n)
                return true;
            
            if (tolower(s[m]) != tolower(s[n]))
                return false;
            m++;
            n--;
        }
        return true;
    }
};


2015.5.16 update
class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "")    return true;
        
        int i = 0, j = s.length() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i]))  i++;
            while (i < j && !isalnum(s[j]))  j--;
            
            if (i < j && tolower(s[i]) != tolower(s[j]))   return false;
            i++; j--;
        }
        return true;
    }
};
