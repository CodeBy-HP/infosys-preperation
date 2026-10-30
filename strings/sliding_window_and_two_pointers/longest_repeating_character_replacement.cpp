#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LongestRepeatingCharacterReplacement {
public:
    // =========================================================================
    // 1. Sliding Window with Max Frequency Invariant
    // Time Complexity: O(N)
    // Space Complexity: O(26) = O(1)
    // =========================================================================
    int characterReplacement(const string& s, int k) {
        vector<int> count(26, 0);
        int maxFreq = 0;
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            // If replacements needed exceed k, slide left forward by 1
            if ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    LongestRepeatingCharacterReplacement solver;

    cout << "Test 1 (\"ABAB\", k=2): " 
         << solver.characterReplacement("ABAB", 2) << " (Expected: 4)\n";

    cout << "Test 2 (\"AABABBA\", k=1): " 
         << solver.characterReplacement("AABABBA", 1) << " (Expected: 4)\n";

    return 0;
}
