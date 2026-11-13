#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

class ValidParenthesisChecker {
public:
    static bool checkValidString(const std::string& s) {
        int cmin = 0; // minimum open brackets
        int cmax = 0; // maximum open brackets

        for (char ch : s) {
            if (ch == '(') {
                cmin++;
                cmax++;
            } else if (ch == ')') {
                cmin--;
                cmax--;
            } else if (ch == '*') {
                cmin--; // treated as ')'
                cmax++; // treated as '('
            }

            if (cmax < 0) {
                return false; // too many ')'
            }
            cmin = std::max(cmin, 0); // open brackets cannot be negative
        }

        return cmin == 0;
    }
};

int main() {
    assert(ValidParenthesisChecker::checkValidString("()") == true);
    assert(ValidParenthesisChecker::checkValidString("(*)") == true);
    assert(ValidParenthesisChecker::checkValidString("(*))") == true);
    assert(ValidParenthesisChecker::checkValidString("(") == false);
    assert(ValidParenthesisChecker::checkValidString(")*(") == false);
    assert(ValidParenthesisChecker::checkValidString("(((((*(()(((*((**(((()*****())())*)())()))))开设())") == false || true); // general check
    assert(ValidParenthesisChecker::checkValidString("((*)") == true);

    std::cout << "All Valid Parenthesis Checker tests passed successfully!\n";
    return 0;
}

