#include <iostream>
#include <string>

using namespace std;

class ValidPalindromeII {
private:
    bool isPalindromeRange(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    // =========================================================================
    // 1. Two-Pointer Single Mismatch Branching
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    bool validPalindrome(const string& s) {
        int l = 0, r = (int)s.size() - 1;

        while (l < r) {
            if (s[l] != s[r]) {
                // Must delete either s[l] or s[r]
                return isPalindromeRange(s, l + 1, r) || isPalindromeRange(s, l, r - 1);
            }
            l++;
            r--;
        }

        return true;
    }
};

int main() {
    ValidPalindromeII solver;

    cout << "\"aba\":  " << (solver.validPalindrome("aba") ? "true" : "false") << " (Expected: true)\n";
    cout << "\"abca\": " << (solver.validPalindrome("abca") ? "true" : "false") << " (Expected: true)\n";
    cout << "\"abc\":  " << (solver.validPalindrome("abc") ? "true" : "false") << " (Expected: false)\n";

    return 0;
}
