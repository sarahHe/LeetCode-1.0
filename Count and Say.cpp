class Solution {
public:
    string countAndSay(int n) {
        if (n < 1)  return "";
            
        string res = "1";
        for (int i = 2; i <= n; i++) {
            string tmp = "";
            int count = 1;
            for (int j = 0; j < res.length()-1; j++) {
                if (res[j] == res[j+1])
                    count++;
                else {
                    tmp += to_string(count) + res[j];
                    count = 1;
                }
            }
            tmp += to_string(count) + res.back();
            res = tmp;
        }
        return res;
    }
};


Another solution with a few changes: // it turns out 1ms slower than the previous one
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 1; i < n; i++) {
            int count = 1;
            string tmp = "";
            for (int j = 1; j <= res.length(); j++) { //j = 1; j <= res.length
                while (j < res.length() && res[j] == res[j-1])  {// while loop,  j < res.length()
                    count++;
                    j++; // j++
                }
                tmp += to_string(count) + res[j-1];
                count = 1;
            }
            res = tmp;
        }
        return res;
    }
};
