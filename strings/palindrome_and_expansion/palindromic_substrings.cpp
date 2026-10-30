#include <iostream>
#include <string>

using namespace std;

class PalindromicSubstrings {
private:
    int countFromCenter(const string& s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }

public:
    // =========================================================================
    // 1. Expand Around Center Counting
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)
    // =========================================================================
    int countSubstrings(const string& s) {
        int total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            total += countFromCenter(s, i, i);     // Odd center
            total += countFromCenter(s, i, i + 1); // Even center
        }
        return total;
    }
};

int main() {
    PalindromicSubstrings solver;

    cout << "Count (\"abc\"): " << solver.countSubstrings("abc") << " (Expected: 3)\n";
    cout << "Count (\"aaa\"): " << solver.countSubstrings("aaa") << " (Expected: 6)\n";

    return 0;
}
