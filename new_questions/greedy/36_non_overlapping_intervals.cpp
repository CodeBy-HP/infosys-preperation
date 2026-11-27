#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        int kept = 1;
        int prevEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= prevEnd) {
                kept++;
                prevEnd = intervals[i][1];
            }
        }
        return static_cast<int>(intervals.size()) - kept;
    }
};

int main() {
    Solution sol;
    assert(sol.eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) == 1);
    assert(sol.eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}}) == 2);
    assert(sol.eraseOverlapIntervals({{1, 2}, {2, 3}}) == 0);
    cout << "36_non_overlapping_intervals passed all tests!\n";
    return 0;
}
