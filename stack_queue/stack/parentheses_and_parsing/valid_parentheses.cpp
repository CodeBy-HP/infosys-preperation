#include <iostream>
#include <string>
#include <stack>

using namespace std;

class ValidParentheses {
public:
    // =========================================================================
    // 1. Stack Matching
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    bool isValid(const string& s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '{') st.push('}');
            else if (c == '[') st.push(']');
            else {
                // Closing bracket: must match expected top
                if (st.empty() || st.top() != c) return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    ValidParentheses solver;

    cout << "\"()[]{}\": " << (solver.isValid("()[]{}") ? "true" : "false") << " (Expected: true)\n";
    cout << "\"(]\":     " << (solver.isValid("(]") ? "true" : "false") << " (Expected: false)\n";

    return 0;
}
