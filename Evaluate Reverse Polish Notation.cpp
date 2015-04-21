2015.4.20 update
//run time reduced from 56ms to 18ms
int evalRPN(vector<string>& tokens) {
    stack<int> numbers;
    for (auto i : tokens) {
        int n1, n2;
        if (i == "+") {
                n1 = numbers.top();
                numbers.pop();
                n2 = numbers.top();
                numbers.pop();
                numbers.push(n1 + n2);
        }
        else if (i == "-") {
                n1 = numbers.top();
                numbers.pop();
                n2 = numbers.top();
                numbers.pop();
                numbers.push(n2 - n1);
        }
        else if (i == "*") {
                n1 = numbers.top();
                numbers.pop();
                n2 = numbers.top();
                numbers.pop();
                numbers.push(n1 * n2);
        }
        else if (i == "/") {
                n1 = numbers.top();
                numbers.pop();
                n2 = numbers.top();
                numbers.pop();
                numbers.push(n2 / n1);
        }
        else
            numbers.push(stoi(i));
    }
    return numbers.top();
}


//Found a cool recursive way. A bit slow
int eval_expression(vector<string>& tokens, int& pt)
{
    string s = tokens[pt];

    if(s == "+" || s == "-" || s == "*" || s== "/") // tokens[r] is an operator
    {
        pt--;
        int v2 = eval_expression(tokens, pt);
        pt--;
        int v1 = eval_expression(tokens, pt);
        if(s == "+")
            return v1 + v2;
        else if(s == "-")
            return v1 - v2;
        else if(s == "*")
            return v1 * v2;
        else 
            return v1 / v2;
    }
    else // tokens[r] is a number
    {
        return atoi(s.c_str());
    }
}

int evalRPN(vector<string> &tokens) {
    int pt = tokens.size()-1; 
    return eval_expression(tokens, pt);
}
