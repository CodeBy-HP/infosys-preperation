#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class LongestContiguousSubarray {
public:
    // =========================================================================
    // 1. Linear Scan Window Reset
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int longestSubarrayBoundedDiff(const vector<int>& arr, int L) {
        int n = arr.size();
        if (n <= 1) return n;

        int maxLen = 1;
        int currentLen = 1;

        for (int i = 1; i < n; i++) {
            if (abs((long long)arr[i] - arr[i - 1]) <= L) {
                currentLen++;
            } else {
                currentLen = 1;
            }
            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};

int main() {
    LongestContiguousSubarray solver;

    vector<int> arr = {4, 5, 9, 3, 2, 1, 45, 3, 4};
    int L = 3;

    cout << "Longest Contiguous Subarray Length: " 
         << solver.longestSubarrayBoundedDiff(arr, L) << "\n";

    return 0;
}
