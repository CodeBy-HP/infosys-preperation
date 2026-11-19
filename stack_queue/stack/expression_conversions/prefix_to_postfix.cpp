#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class PrefixToPostfix {
public:
    string convert(const string& prefix) {
        stack<string> st;

        // Traverse right-to-left
        for (int i = (int)prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];

            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                if (st.size() < 2) return "";
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                // Postfix ordering: operand1 + operand2 + operator
                string combined = op1 + op2 + c;
                st.push(combined);
            }
        }

        return st.empty() ? "" : st.top();
    }
};

int main() {
    PrefixToPostfix solver;

    string prefix1 = "*+AB-CD";
    cout << "Prefix:  " << prefix1 << "\n";
    cout << "Postfix: " << solver.convert(prefix1) << " (Expected: AB+CD-*)\n\n";

    string prefix2 = "*-A/BC-/AKL";
    cout << "Prefix:  " << prefix2 << "\n";
    cout << "Postfix: " << solver.convert(prefix2) << " (Expected: ABC/-AK/L-*)\n";

    return 0;
}

