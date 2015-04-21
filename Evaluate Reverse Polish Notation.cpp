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
