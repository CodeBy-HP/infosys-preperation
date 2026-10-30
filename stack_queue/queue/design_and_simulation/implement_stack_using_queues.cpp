#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}

    // Push element x onto stack: rotate previous elements behind x
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    std::cout << "top():   " << st.top() << " (Expected: 3)\n";
    std::cout << "pop():   " << st.pop() << " (Expected: 3)\n";
    std::cout << "top():   " << st.top() << " (Expected: 2)\n";
    std::cout << "pop():   " << st.pop() << " (Expected: 2)\n";
    std::cout << std::boolalpha << "empty(): " << st.empty() << " (Expected: false)\n";
    std::cout << "pop():   " << st.pop() << " (Expected: 1)\n";
    std::cout << "empty(): " << st.empty() << " (Expected: true)\n";

    return 0;
}
