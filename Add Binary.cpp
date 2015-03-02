class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        string res = "";
        int flag = 0;
        while (i >= 0 && j >= 0) {
            int k = a[i]-'0' + b[j]-'0';
            if (k + flag > 1) {
                res = to_string(k + flag - 2) + res;
                flag = 1;
            }
            else {
                res = to_string(k + flag) + res;
                flag = 0;
            }
            i--; j--;
        }

        while (j >= 0) {
            if (b[j] - '0' + flag > 1) {
                res = '0' + res;
            }
            else {
                int tmp = b[j] - '0' + flag;
                res = to_string(tmp) + res;
                flag = 0;
            }
            j--;
        }

        while (i >= 0) {
            if (a[i]-'0' + flag > 1) {
                res = '0' + res;
            }
            else {
                int tmp = a[i] - '0' + flag;
                res = to_string(tmp) + res;
                flag = 0;
            }
            i--;
        }
        if (flag)
            res = '1' + res;

        return res;
    }
};
