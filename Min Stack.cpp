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


2015.4.20 update
// refer to "discussion"
// The question is ask to construct One stack. So I am using one stack.
// The idea is to store the gap between the min value and the current value;
// The problem for my solution is the cast. I have no idea to avoid the cast. 
// Since the possible gap between the current value and the min value could be Integer.MAXVALUE-Integer.MINVALUE;
class MinStack {
    int min;
    stack<int> myStack;
public:
    void push(int x) {
        if (myStack.empty()) {
            myStack.push(0);
            min = x;
        }
        else {
            myStack.push(x - min);
            if (x < min)
                min = x;
        }
    }

    void pop() {
        if (myStack.empty())  return;
       
        int top = myStack.top();
        if (top < 0)
            min -= top;
        myStack.pop();
    }

    int top() {
        int top = myStack.top();
        if (top < 0)
            return min;
        else
            return min + top;
    }

    int getMin() {
        return min;
    }
};
