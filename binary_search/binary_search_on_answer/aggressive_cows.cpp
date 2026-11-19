#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class AggressiveCows {
private:
    // Helper to verify if we can place K cows with at least 'dist' separation
    bool canWePlace(const vector<int>& stalls, int dist, int k) {
        int cowsPlaced = 1;
        int lastStall = stalls[0];

        for (size_t i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastStall >= dist) {
                cowsPlaced++;
                lastStall = stalls[i];
            }
            if (cowsPlaced >= k) return true;
        }
        return false;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search on Distance
    // Time Complexity: O(N log N + N * log(max_stall - min_stall))
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    int aggressiveCowsOptimal(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int left = 1;
        int right = stalls[n - 1] - stalls[0];
        int ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canWePlace(stalls, mid, k)) {
                ans = mid;        // Feasible, attempt a larger minimum distance
                left = mid + 1;
            } else {
                right = mid - 1;  // Distance too large, decrease it
            }
        }
        return ans;
    }
};

int main() {
    AggressiveCows solver;

    vector<int> stalls1 = {1, 2, 8, 4, 9};
    int k1 = 3;
    cout << "Test 1: " << solver.aggressiveCowsOptimal(stalls1, k1) << " (Expected: 3)\n";

    vector<int> stalls2 = {0, 3, 4, 7, 10, 9};
    int k2 = 4;
    cout << "Test 2: " << solver.aggressiveCowsOptimal(stalls2, k2) << " (Expected: 3)\n";

    return 0;
}

