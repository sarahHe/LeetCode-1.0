2015.5.28 update
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int o2 = s.top();
                s.pop();
                int o1 = s.top();
                s.pop();
                if (tokens[i] == "+")
                    s.push(o1 + o2);
                else if (tokens[i] == "-")
                    s.push(o1 - o2);
                else if (tokens[i] == "*")
                    s.push(o1 * o2);
                else
                    s.push(o1 / o2);
            } else 
                s.push(stoi(tokens[i]));
        }
        return s.top();
    }
};

int evalRPN(vector<string> &tokens) {
    int pt = tokens.size()-1; 
    return eval_expression(tokens, pt);
}
