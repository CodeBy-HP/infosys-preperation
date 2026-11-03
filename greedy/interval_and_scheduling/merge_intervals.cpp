#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Merge Intervals (LeetCode 56)
 * 
 * Problem:
 * Given a list of proposed meeting time slots [start, end], merge all
 * overlapping intervals and return them sorted by start times.
 * 
 * Time Complexity: O(N log N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Step 1: Sort intervals by start time ascending
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        // Step 2: Linear sweep to merge overlapping ranges
        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i) {
            auto& last = merged.back();
            const auto& curr = intervals[i];

            // Overlap condition: current interval starts before or at the end of the previous
            if (curr[0] <= last[1]) {
                last[1] = std::max(last[1], curr[1]);
            } else {
                merged.push_back(curr);
            }
        }

        return merged;
    }
};

int main() {
    Solution solver;

    // Test 1: Standard overlapping intervals
    {
        std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        std::vector<std::vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};
        std::vector<std::vector<int>> actual = solver.merge(intervals);
        assert(actual == expected);
    }

    // Test 2: Touching intervals
    {
        std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};
        std::vector<std::vector<int>> expected = {{1, 5}};
        std::vector<std::vector<int>> actual = solver.merge(intervals);
        assert(actual == expected);
    }

    // Test 3: Fully nested intervals
    {
        std::vector<std::vector<int>> intervals = {{1, 10}, {2, 5}, {6, 8}};
        std::vector<std::vector<int>> expected = {{1, 10}};
        std::vector<std::vector<int>> actual = solver.merge(intervals);
        assert(actual == expected);
    }

    std::cout << "All Merge Intervals test cases passed successfully!" << std::endl;
    return 0;
}

