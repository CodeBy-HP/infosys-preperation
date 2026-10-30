#include <iostream>
#include <string>
#include <stack>
#include <numeric>

using namespace std;

class BasicCalculatorII {
public:
    // =========================================================================
    // 1. Stack Precedence Evaluation
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int calculate(const string& s) {
        stack<int> st;
        long long currentNum = 0;
        char op = '+';
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                currentNum = currentNum * 10 + (c - '0');
            }

            // Process operator or final token
            if ((!isdigit(c) && c != ' ') || i == n - 1) {
                if (op == '+') {
                    st.push(currentNum);
                } else if (op == '-') {
                    st.push(-currentNum);
                } else if (op == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * currentNum);
                } else if (op == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / currentNum);
                }

                op = c;
                currentNum = 0;
            }
        }

        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    BasicCalculatorII solver;

    cout << "\"3+2*2\": " << solver.calculate("3+2*2") << " (Expected: 7)\n";
    cout << "\" 3/2 \": " << solver.calculate(" 3/2 ") << " (Expected: 1)\n";
    cout << "\" 3+5 / 2 \": " << solver.calculate(" 3+5 / 2 ") << " (Expected: 5)\n";

    return 0;
}
