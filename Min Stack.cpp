// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

//maintain two stacks, one is normal, another stores the so far min

class MinStack {
public:
    void push(int x) {
        s1.push(x);
        if (s_min.empty())
            s_min.push(x);
        else {
            if (s_min.top() >= x) // >=
                s_min.push(x);
        }
    }

    void pop() {
        if (s1.top() <= s_min.top()) <=
            s_min.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s_min.top();
    }
private:
    stack<int> s1, s_min;
};
