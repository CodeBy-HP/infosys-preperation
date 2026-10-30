#include <iostream>
#include <string>
#include <vector>

using namespace std;

class RemoveDuplicateLetters {
public:
    // =========================================================================
    // 1. Monotonic Stack with Last Occurrence Lookup
    // Time Complexity: O(N)
    // Space Complexity: O(26) = O(1)
    // =========================================================================
    string removeDuplicateLetters(const string& s) {
        vector<int> lastIndex(26, 0);
        for (int i = 0; i < (int)s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        vector<bool> inStack(26, false);
        string result = "";

        for (int i = 0; i < (int)s.size(); i++) {
            char c = s[i];
            if (inStack[c - 'a']) continue;

            // Pop characters that are lexicographically larger AND appear later
            while (!result.empty() && result.back() > c && lastIndex[result.back() - 'a'] > i) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inStack[c - 'a'] = true;
        }

        return result;
    }
};

int main() {
    RemoveDuplicateLetters solver;

    cout << "\"bcabc\":    " << solver.removeDuplicateLetters("bcabc") << " (Expected: \"abc\")\n";
    cout << "\"cbacdcbc\": " << solver.removeDuplicateLetters("cbacdcbc") << " (Expected: \"acdb\")\n";

    return 0;
}
