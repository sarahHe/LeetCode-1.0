// Given a string containing just the characters '(' and ')', 
// find the length of the longest valid (well-formed) parentheses substring.
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

class Solution {
//should be consecutive sub-string
public:
    int longestValidParentheses(string s) {
        stack<int> st; // store the index. important
        int i = 0, local = 0, global = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else { //s[i] == ')'
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                    // if pairs before i are all valid, st is empty
                    local = st.empty() ? i +1 : i - st.top();
                    global = max(global, local);
                }
                else 
                    st.push(i);
            }
        }
        return global;
    }
};
