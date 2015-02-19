class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1)
            return s;//!!!!
        string res = "";
        int gap = 2*(nRows - 1);
        for (int i = 0; i < nRows; i++) {
            for (int j = i; j < s.length(); j += gap) {
                res += s[j];
                if (i !=0 && i != nRows-1 && j + gap - 2 * i < s.length())
                    res += s[j + gap - 2 * i];
            }
        }
        return res;
    }
};
