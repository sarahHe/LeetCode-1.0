/*
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

之前用的递归的方法 空间复杂度高。
看到reverse 就要想到 可以用栈
*/
class Solution {
public:
    void reverseWords(string &s) {
        if (s == "")    return;
        stack<string> reverse;
        int len = s.length();
        int i = 0;
        while (i < len) {
            int k = i;
            while (s[k] == ' ' && k < len)
                k++;
            i = k; //以上三行是为了“ a”这种case。以空格开始。
            while (s[k] != ' ' && k < len)
                k++;
            reverse.push(s.substr(i, k - i));
            while (s[k] == ' ' && k < len)
                k++;
            i = k;
        }
        s = "";
        while (!reverse.empty()) {
            s += reverse.top() + " ";
            reverse.pop();
        }
        s = s.substr(0, s.length() - 1);
    }
};


2015.4.20 update
//can't remove empty space
void reverse(string &s, int i, int j) { // j is 1 + end
    while (i < j-1) {
        swap(s[i], s[j-1]);
        i++; j--;
    }
}

void reverseWords(string &s) {
    if (s == "")    return;
    
    reverse(s, 0, (int)s.length());
    int i = 0;
    while(i < s.length()) {
        while (i < s.length() && s[i] == ' ')
            i++;
        
        int j = i;
        while (j < s.length() && s[j] != ' ')
            j++;
        
        reverse(s, i, j);
        i = j;
    }
}
