#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

class InfixToPrefix {
private:
    static int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

public:
    string convert(string s) {
        // Step 1: Reverse infix string
        reverse(s.begin(), s.end());

        // Step 2: Invert parentheses
        for (char& c : s) {
            if (c == '(') c = ')';
            else if (c == ')') c = '(';
        }

        // Step 3: Modified Postfix conversion
        stack<char> st;
        string postfix = "";

        for (char c : s) {
            if (isalnum(c)) {
                postfix += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else {
                // For reversed infix: pop if precedence(top) > precedence(curr)
                // for right-associative (^), pop if precedence(top) >= precedence(curr)
                while (!st.empty() && st.top() != '(') {
                    int pTop = precedence(st.top());
                    int pCurr = precedence(c);

                    if (c == '^' ? pTop >= pCurr : pTop > pCurr) {
                        postfix += st.top();
                        st.pop();
                    } else {
                        break;
                    }
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }

        // Step 4: Reverse postfix to obtain prefix
        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};

int main() {
    InfixToPrefix solver;

    string expr = "(A+B)*C-D+F";
    cout << "Infix: " << expr << "\n";
    cout << "Prefix: " << solver.convert(expr) << " (Expected: +-*+ABCDF)\n";

    return 0;
}

