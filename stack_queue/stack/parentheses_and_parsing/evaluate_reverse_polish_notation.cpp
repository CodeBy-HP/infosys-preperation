#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class EvaluateRPN {
public:
    // =========================================================================
    // 1. Stack Evaluation
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int evalRPN(const vector<string>& tokens) {
        stack<long long> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);
            } else {
                st.push(stoll(token));
            }
        }

        return (int)st.top();
    }
};

int main() {
    EvaluateRPN solver;

    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    cout << "Test 1: " << solver.evalRPN(tokens1) << " (Expected: 9)\n";

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    cout << "Test 2: " << solver.evalRPN(tokens2) << " (Expected: 6)\n";

    return 0;
}
