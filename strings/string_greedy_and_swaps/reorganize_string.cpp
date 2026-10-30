#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ReorganizeString {
public:
    // =========================================================================
    // 1. Even/Odd Stride Placement
    // Time Complexity: O(N)
    // Space Complexity: O(26) = O(1)
    // =========================================================================
    string reorganizeString(const string& s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int maxFreq = 0;
        char maxChar = 'a';
        for (int i = 0; i < 26; i++) {
            if (count[i] > maxFreq) {
                maxFreq = count[i];
                maxChar = 'a' + i;
            }
        }

        int n = s.size();
        if (maxFreq > (n + 1) / 2) return "";

        string result(n, ' ');
        int idx = 0;

        // Place most frequent character at even indices
        while (count[maxChar - 'a'] > 0) {
            result[idx] = maxChar;
            idx += 2;
            count[maxChar - 'a']--;
        }

        // Place remaining characters
        for (int i = 0; i < 26; i++) {
            while (count[i] > 0) {
                if (idx >= n) idx = 1; // Wrap to odd indices
                result[idx] = 'a' + i;
                idx += 2;
                count[i]--;
            }
        }

        return result;
    }
};

int main() {
    ReorganizeString solver;

    cout << "\"aab\":  " << solver.reorganizeString("aab") << " (Expected: \"aba\")\n";
    cout << "\"aaab\": \"" << solver.reorganizeString("aaab") << "\" (Expected: \"\")\n";

    return 0;
}
