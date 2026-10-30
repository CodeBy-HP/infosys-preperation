#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxCyclicPrefixXORSum {
private:
    long long evaluateDirection(const vector<int>& arr) {
        int n = arr.size();
        // Duplicate array to handle cyclic wrap-around
        vector<int> doubled(2 * n);
        for (int i = 0; i < 2 * n; i++) doubled[i] = arr[i % n];

        vector<int> prefixXor(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            prefixXor[i + 1] = prefixXor[i] ^ doubled[i];
        }

        long long maxVal = 0;

        // Try each starting index
        for (int start = 0; start < n; start++) {
            long long currentSum = 0;
            int basePrefix = prefixXor[start];

            for (int len = 1; len <= n; len++) {
                int currXor = prefixXor[start + len] ^ basePrefix;
                currentSum += currXor;
            }
            maxVal = max(maxVal, currentSum);
        }

        return maxVal;
    }

public:
    // =========================================================================
    // 1. Cyclic Prefix XOR Search
    // Time Complexity: O(N^2) / O(30 * N) bitwise
    // Space Complexity: O(N)
    // =========================================================================
    long long maxCyclicXORSum(vector<int>& arr) {
        long long resForward = evaluateDirection(arr);

        // Reverse to evaluate other direction
        reverse(arr.begin(), arr.end());
        long long resBackward = evaluateDirection(arr);

        return max(resForward, resBackward);
    }
};

int main() {
    MaxCyclicPrefixXORSum solver;

    vector<int> arr = {1, 2, 4, 5, 8};
    cout << "Max Cyclic Prefix XOR Sum: " << solver.maxCyclicXORSum(arr) << " (Expected: 53)\n";

    return 0;
}
