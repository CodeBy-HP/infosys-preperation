#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // LeetCode 1751: Max Profit with at most K non-overlapping intervals (end1 < start2)
    long long maxValueKIntervals(vector<vector<int>> events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = events[i][0];

        vector<int> nextIdx(n);
        for (int i = 0; i < n; i++) {
            nextIdx[i] = upper_bound(starts.begin() + i + 1, starts.end(), events[i][1]) - starts.begin();
        }

        vector<long long> dp(n + 1, 0);
        for (int c = 1; c <= k; c++) {
            vector<long long> nextDp(n + 1, 0);
            for (int i = n - 1; i >= 0; i--) {
                long long skip = nextDp[i + 1];
                long long take = events[i][2] + dp[nextIdx[i]];
                nextDp[i] = max(skip, take);
            }
            dp.swap(nextDp);
        }
        return dp[0];
    }

    // LeetCode 1235: Unbounded number of intervals (end1 <= start2)
    int jobSchedulingUnlimited(const vector<int>& startTime, const vector<int>& endTime, const vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = {startTime[i], endTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());

        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = jobs[i][0];

        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int nxt = lower_bound(starts.begin() + i + 1, starts.end(), jobs[i][1]) - starts.begin();
            dp[i] = max(dp[i + 1], jobs[i][2] + dp[nxt]);
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    assert(sol.maxValueKIntervals({{1, 2, 4}, {3, 4, 3}, {2, 3, 1}}, 2) == 7);
    assert(sol.maxValueKIntervals({{1, 2, 4}, {3, 4, 3}, {2, 3, 10}}, 2) == 10);
    assert(sol.jobSchedulingUnlimited({1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}) == 120);
    cout << "26_max_profit_k_intervals passed all tests!\n";
    return 0;
}
