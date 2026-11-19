#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class InfixToPostfix {
private:
    static int precedence(char op) {
        if (op == '^') return 3;
        if (op == '*' || op == '/') return 2;
        if (op == '+' || op == '-') return 1;
        return -1;
    }

    static bool isRightAssociative(char op) {
        return op == '^';
    }

public:
    string convert(const string& s) {
        stack<char> st;
        string result = "";

        for (char c : s) {
            if (isalnum(c)) {
                result += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    result += st.top();
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
            } else {
                // Operator
                while (!st.empty() && st.top() != '(') {
                    int pCurr = precedence(c);
                    int pTop = precedence(st.top());

                    if (pTop > pCurr || (pTop == pCurr && !isRightAssociative(c))) {
                        result += st.top();
                        st.pop();
                    } else {
                        break;
                    }
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

int main() {
    InfixToPostfix solver;

    string expr1 = "(p+q)*(m-n)";
    cout << "Infix: " << expr1 << "\n";
    cout << "Postfix: " << solver.convert(expr1) << " (Expected: pq+mn-*)\n\n";

    string expr2 = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << expr2 << "\n";
    cout << "Postfix: " << solver.convert(expr2) << " (Expected: abcd^e-fgh*+^*+i-)\n";

    return 0;
}

