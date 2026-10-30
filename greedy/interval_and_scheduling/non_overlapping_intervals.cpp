#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NonOverlappingIntervals {
public:
    // =========================================================================
    // 1. Optimal Greedy Approach (Sort by End Time)
    // Always keep the interval that finishes earliest to maximize future room.
    // Time Complexity: O(N log N)
    // Space Complexity: O(1) (ignoring sort recursion stack)
    // =========================================================================
    int eraseOverlapIntervalsByEndTime(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort primarily by end time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removals = 0;
        int lastEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < lastEnd) {
                // Overlap: current interval finishes later; remove current
                removals++;
            } else {
                // Compatible: keep current and advance boundary
                lastEnd = intervals[i][1];
            }
        }

        return removals;
    }

    // =========================================================================
    // 2. Alternative Greedy Approach (Sort by Start Time)
    // If an overlap occurs, greedily drop the one with the larger end time.
    // Time Complexity: O(N log N)
    // Space Complexity: O(1)
    // =========================================================================
    int eraseOverlapIntervalsByStartTime(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end());

        int removals = 0;
        int prevEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) {
                // Overlap: remove the one that ends later
                removals++;
                prevEnd = min(prevEnd, intervals[i][1]);
            } else {
                // No overlap
                prevEnd = intervals[i][1];
            }
        }

        return removals;
    }

    // =========================================================================
    // 3. Dynamic Programming Approach (LIS Style - Educational Baseline)
    // dp[i] = max non-overlapping intervals ending at interval i
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // =========================================================================
    int eraseOverlapIntervalsDP(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;

        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, 1);
        int maxKept = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (intervals[j][1] <= intervals[i][0]) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            maxKept = max(maxKept, dp[i]);
        }

        return n - maxKept;
    }
};

int main() {
    NonOverlappingIntervals solver;

    vector<vector<int>> intervals1 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << "Test 1 [[1,2],[2,3],[3,4],[1,3]]:\n";
    cout << "  By End Time:   " << solver.eraseOverlapIntervalsByEndTime(intervals1) << "\n";
    cout << "  By Start Time: " << solver.eraseOverlapIntervalsByStartTime(intervals1) << "\n";
    cout << "  By DP:         " << solver.eraseOverlapIntervalsDP(intervals1) << " (Expected: 1)\n";

    vector<vector<int>> intervals2 = {{1, 2}, {1, 2}, {1, 2}};
    cout << "Test 2 [[1,2],[1,2],[1,2]]:\n";
    cout << "  By End Time:   " << solver.eraseOverlapIntervalsByEndTime(intervals2) << " (Expected: 2)\n";

    return 0;
}

