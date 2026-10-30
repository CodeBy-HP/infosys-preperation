#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MinSwapsGroupOnesOrZeros {
public:
    // =========================================================================
    // 1. Optimal Single-Pass Obstacle Jump Counting
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    long long minAdjacentSwaps(const string& s) {
        int total0 = 0, total1 = 0;
        for (char c : s) {
            if (c == '0') total0++;
            else total1++;
        }

        if (total0 == 0 || total1 == 0) return 0;

        long long swapsGroup0 = 0;
        long long swapsGroup1 = 0;
        int count0Left = 0;
        int count1Left = 0;

        for (char c : s) {
            if (c == '0') {
                count0Left++;
                // When grouping '1's, this '0' is jumped over by smaller side of 1s
                swapsGroup1 += min(count1Left, total1 - count1Left);
            } else {
                count1Left++;
                // When grouping '0's, this '1' is jumped over by smaller side of 0s
                swapsGroup0 += min(count0Left, total0 - count0Left);
            }
        }

        return min(swapsGroup0, swapsGroup1);
    }
};

int main() {
    MinSwapsGroupOnesOrZeros solver;

    cout << "\"1001\":  " << solver.minAdjacentSwaps("1001") << " (Expected: 0)\n";
    cout << "\"10101\": " << solver.minAdjacentSwaps("10101") << " (Expected: 1)\n";

    return 0;
}
