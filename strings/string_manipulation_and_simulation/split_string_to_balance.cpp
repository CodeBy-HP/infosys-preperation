#include <iostream>
#include <string>

using namespace std;

class SplitStringToBalance {
public:
    // =========================================================================
    // 1. Single Pass Prefix Difference with Potential Swap Gain
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int maxBalancedSplits(const string& s) {
        int n = s.length();
        int freqL = 0;
        int freqR = 0;
        int naturalSplits = 0;
        bool canGainSplit = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') freqL++;
            else freqR++;

            int diff = freqL - freqR;

            if (diff == 0) {
                naturalSplits++;
            }

            // Check if swapping adjacent pair (i, i+1) creates an extra split at i
            if (!canGainSplit && i < n - 1) {
                if (diff == 2 && s[i] == 'L' && s[i + 1] == 'R') {
                    canGainSplit = true;
                } else if (diff == -2 && s[i] == 'R' && s[i + 1] == 'L') {
                    canGainSplit = true;
                }
            }
        }

        return canGainSplit ? naturalSplits + 1 : naturalSplits;
    }
};

int main() {
    SplitStringToBalance solver;

    cout << "\"RLRRLLRLRL\": " << solver.maxBalancedSplits("RLRRLLRLRL") << " (Expected: 4)\n";
    cout << "\"LLRR\":       " << solver.maxBalancedSplits("LLRR") << " (Expected: 2, swap middle LR to get LRLR)\n";

    return 0;
}
