// Implement strStr().
// Returns the index of the first occurrence of needle in 
// haystack, or -1 if needle is not part of haystack.

//just try to reduce the comparing times
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack),
            len2 = strlen(needle),
            c = 0;
        if (len1 < len2)
            return -1;
        if (!len2)
            return 0;
        
        while (c <= len1 - len2 && haystack+c) {
            char *t1 = haystack+c, *t2 = needle;
            while (*t2 != '\0') {
                if (*t1 != *t2)
                    break;
                    
                t1++; 
                t2++;
            }

            if (*t2 == '\0')
                return c;
            c++;
        }
        return -1;
    }
};


2015.2.28 recursion:
class Solution {
public:
   int hayStackHelper(char *haystack, char *needle, int start, int pos) {
        if (*(needle + pos) == '\0')
            return start;
        else if (*(haystack + start + pos) == '\0') {
            return - 1;
        }
        
        if (*(haystack + start + pos) != *(needle + pos)) {
            start++;
            pos = 0;
        }
        else
            pos++;
        return hayStackHelper(haystack , needle, start, pos);
    }
    
    int strStr(char *haystack, char *needle) {
        int idx = 0, pos = 0;
        if (*needle == '\0')
            return 0;
        return hayStackHelper(haystack, needle, idx, pos);
    }
};
