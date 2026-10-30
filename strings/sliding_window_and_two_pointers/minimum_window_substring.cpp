#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class MinimumWindowSubstring {
public:
    // =========================================================================
    // 1. Two-Pointer Sliding Window with Count Invariant
    // Time Complexity: O(M + N) where M = s.size(), N = t.size()
    // Space Complexity: O(128) = O(1) auxiliary space
    // =========================================================================
    string minWindow(const string& s, const string& t) {
        if (s.empty() || t.empty() || s.size() < t.size()) return "";

        vector<int> targetCount(128, 0);
        int required = 0;
        for (char c : t) {
            if (targetCount[(unsigned char)c] == 0) required++;
            targetCount[(unsigned char)c]++;
        }

        vector<int> windowCount(128, 0);
        int formed = 0;
        int left = 0;

        int minLen = INT_MAX;
        int minStart = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            windowCount[(unsigned char)c]++;

            if (targetCount[(unsigned char)c] > 0 && 
                windowCount[(unsigned char)c] == targetCount[(unsigned char)c]) {
                formed++;
            }

            // Try contracting window from the left as long as it remains valid
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                char leftChar = s[left];
                windowCount[(unsigned char)leftChar]--;
                if (targetCount[(unsigned char)leftChar] > 0 && 
                    windowCount[(unsigned char)leftChar] < targetCount[(unsigned char)leftChar]) {
                    formed--;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};

int main() {
    MinimumWindowSubstring solver;

    cout << "Test 1 (\"ADOBECODEBANC\", \"ABC\"): " 
         << solver.minWindow("ADOBECODEBANC", "ABC") << " (Expected: BANC)\n";

    cout << "Test 2 (\"a\", \"a\"): " 
         << solver.minWindow("a", "a") << " (Expected: a)\n";

    cout << "Test 3 (\"a\", \"aa\"): \"" 
         << solver.minWindow("a", "aa") << "\" (Expected: \"\")\n";

    return 0;
}
