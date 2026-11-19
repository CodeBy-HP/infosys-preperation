#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class PostfixToInfix {
public:
    string convert(const string& postfix) {
        stack<string> st;

        // Traverse left-to-right
        for (char c : postfix) {
            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                if (st.size() < 2) return "";
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();

                string combined = "(" + op1 + c + op2 + ")";
                st.push(combined);
            }
        }

        return st.empty() ? "" : st.top();
    }
};

int main() {
    PostfixToInfix solver;

    string postfix1 = "ab+c*";
    cout << "Postfix: " << postfix1 << "\n";
    cout << "Infix:   " << solver.convert(postfix1) << " (Expected: ((a+b)*c))\n\n";

    string postfix2 = "ab+cd-*";
    cout << "Postfix: " << postfix2 << "\n";
    cout << "Infix:   " << solver.convert(postfix2) << " (Expected: ((a+b)*(c-d)))\n";

    return 0;
}

