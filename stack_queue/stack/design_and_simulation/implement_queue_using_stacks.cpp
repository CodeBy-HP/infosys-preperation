#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void transfer() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        transfer();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        transfer();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    cout << "peek():  " << q.peek() << " (Expected: 1)\n";
    cout << "pop():   " << q.pop() << " (Expected: 1)\n";
    cout << "empty(): " << (q.empty() ? "true" : "false") << " (Expected: false)\n";

    return 0;
}
