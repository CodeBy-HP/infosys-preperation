#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class PrefixToInfix {
public:
    string convert(const string& prefix) {
        stack<string> st;

        // Traverse right-to-left
        for (int i = (int)prefix.length() - 1; i >= 0; i--) {
            char c = prefix[i];

            if (isalnum(c)) {
                st.push(string(1, c));
            } else {
                if (st.size() < 2) return ""; // Invalid expression safeguard
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string combined = "(" + op1 + c + op2 + ")";
                st.push(combined);
            }
        }

        return st.empty() ? "" : st.top();
    }
};

int main() {
    PrefixToInfix solver;

    string prefix1 = "*+AB-CD";
    cout << "Prefix: " << prefix1 << "\n";
    cout << "Infix:  " << solver.convert(prefix1) << " (Expected: ((A+B)*(C-D)))\n\n";

    string prefix2 = "*-A/BC-/AKL";
    cout << "Prefix: " << prefix2 << "\n";
    cout << "Infix:  " << solver.convert(prefix2) << " (Expected: ((A-(B/C))*((A/K)-L)))\n";

    return 0;
}

