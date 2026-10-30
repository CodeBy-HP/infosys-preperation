#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinRemoveValidParentheses {
public:
    // =========================================================================
    // 1. Stack Invalidation Marking
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    string minRemoveToMakeValid(string s) {
        stack<int> openIndices;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '(') {
                openIndices.push(i);
            } else if (s[i] == ')') {
                if (!openIndices.empty()) {
                    openIndices.pop(); // Matched pair
                } else {
                    s[i] = '*'; // Mark invalid closing paren
                }
            }
        }

        // Mark remaining unmatched open parens
        while (!openIndices.empty()) {
            s[openIndices.top()] = '*';
            openIndices.pop();
        }

        // Build result excluding marked characters
        string result = "";
        for (char c : s) {
            if (c != '*') result += c;
        }

        return result;
    }
};

int main() {
    MinRemoveValidParentheses solver;

    cout << "\"lee(t(c)o)de)\": " << solver.minRemoveToMakeValid("lee(t(c)o)de)") << " (Expected: lee(t(c)o)de)\n";
    cout << "\"a)b(c)d\":        " << solver.minRemoveToMakeValid("a)b(c)d") << " (Expected: ab(c)d)\n";

    return 0;
}
