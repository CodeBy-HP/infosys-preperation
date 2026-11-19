#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class PostfixToPrefix {
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

                // Prefix ordering: operator + operand1 + operand2
                string combined = c + op1 + op2;
                st.push(combined);
            }
        }

        return st.empty() ? "" : st.top();
    }
};

int main() {
    PostfixToPrefix solver;

    string postfix1 = "AB+CD-*";
    cout << "Postfix: " << postfix1 << "\n";
    cout << "Prefix:  " << solver.convert(postfix1) << " (Expected: *+AB-CD)\n\n";

    string postfix2 = "ABC/-AK/L-*";
    cout << "Postfix: " << postfix2 << "\n";
    cout << "Prefix:  " << solver.convert(postfix2) << " (Expected: *-A/BC-/AKL)\n";

    return 0;
}

