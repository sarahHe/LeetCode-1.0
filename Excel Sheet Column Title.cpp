class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            char tmp = (n - 1) % 26 + 'A'; // n-1 
            res = tmp + res; // tmp 在前
            n = (n-1) / 26; // n-1
        }
        return res;
    }
};
