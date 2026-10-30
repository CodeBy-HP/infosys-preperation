#include <iostream>
#include <vector>

using namespace std;

class RangeAddition {
public:
    // =========================================================================
    // 1. Difference Array Prefix Accumulation
    // Time Complexity: O(N + K) where N = length, K = updates.size()
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> getModifiedArray(int length, const vector<vector<int>>& updates) {
        vector<int> diff(length, 0);

        // Apply O(1) difference markers
        for (const auto& u : updates) {
            int start = u[0];
            int end = u[1];
            int inc = u[2];

            diff[start] += inc;
            if (end + 1 < length) {
                diff[end + 1] -= inc;
            }
        }

        // Compute prefix sum to reconstruct final array
        for (int i = 1; i < length; i++) {
            diff[i] += diff[i - 1];
        }

        return diff;
    }
};

int main() {
    RangeAddition solver;

    vector<vector<int>> updates = {{1, 3, 2}, {2, 4, 3}, {0, 2, -2}};
    vector<int> res = solver.getModifiedArray(5, updates);

    cout << "Final Array: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ -2 0 3 5 3 ])\n";

    return 0;
}
