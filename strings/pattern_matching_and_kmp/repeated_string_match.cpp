#include <iostream>
#include <string>

using namespace std;

class RepeatedStringMatch {
private:
    bool contains(const string& haystack, const string& needle) {
        return haystack.find(needle) != string::npos;
    }

public:
    // =========================================================================
    // 1. Bounded Growth String Matching
    // Time Complexity: O(N * (M/N + 2))
    // Space Complexity: O(N * (M/N + 2))
    // =========================================================================
    int repeatedStringMatch(const string& a, const string& b) {
        string repeated = "";
        int count = 0;

        // Repeat until length is at least b.size()
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        if (contains(repeated, b)) return count;

        // Try one more repeat for overlapping boundary
        repeated += a;
        count++;
        if (contains(repeated, b)) return count;

        return -1;
    }
};

int main() {
    RepeatedStringMatch solver;

    cout << "Test 1 (\"abcd\", \"cdabcdab\"): " 
         << solver.repeatedStringMatch("abcd", "cdabcdab") << " (Expected: 3)\n";

    cout << "Test 2 (\"a\", \"aa\"): " 
         << solver.repeatedStringMatch("a", "aa") << " (Expected: 2)\n";

    return 0;
}
