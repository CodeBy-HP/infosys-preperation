#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<pair<int, int>> st; // {val, currentMin}

public:
    MinStack() {}

    void push(int val) {
        int currentMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};

int main() {
    MinStack ms;

    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << "getMin(): " << ms.getMin() << " (Expected: -3)\n";
    ms.pop();
    cout << "top():    " << ms.top() << " (Expected: 0)\n";
    cout << "getMin(): " << ms.getMin() << " (Expected: -2)\n";

    return 0;
}
