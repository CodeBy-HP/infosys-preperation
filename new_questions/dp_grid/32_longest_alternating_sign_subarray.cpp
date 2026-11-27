#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: LeetCode 978 - Longest Turbulent Subarray
    int maxTurbulenceSize(const vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        int inc = 1, dec = 1, best = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            best = max({best, inc, dec});
        }
        return best;
    }

    // Variant B: Longest Contiguous Subarray with Strictly Alternating Signs (0 breaks chain)
    int maxAlternatingSignSubarray(const vector<int>& arr) {
        int best = 0, curr = 0;
        int prevSign = 0; // +1 for >0, -1 for <0, 0 for zero/none

        for (int x : arr) {
            if (x == 0) {
                curr = 0;
                prevSign = 0;
            } else {
                int sgn = (x > 0) ? 1 : -1;
                if (prevSign == 0 || sgn == -prevSign) {
                    curr++;
                } else {
                    curr = 1;
                }
                prevSign = sgn;
                best = max(best, curr);
            }
        }
        return best;
    }
};

int main() {
    Solution sol;
    assert(sol.maxTurbulenceSize({9, 4, 2, 10, 7, 8, 8, 1, 9}) == 5);
    assert(sol.maxTurbulenceSize({4, 8, 12, 16}) == 2);
    assert(sol.maxAlternatingSignSubarray({1, -2, 3, 4, -5, 6, -7}) == 4);
    assert(sol.maxAlternatingSignSubarray({0, 0}) == 0);
    cout << "32_longest_alternating_sign_subarray passed all tests!\n";
    return 0;
}
