#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxConsecutiveVacation {
public:
    // =========================================================================
    // 1. Sliding Window over Sorted Obligations
    // Time Complexity: O(M log M)
    // Space Complexity: O(M)
    // =========================================================================
    long long maxVacationDays(long long N, int M, int K, vector<long long>& D) {
        if (K >= M) return N; // Cancel all obligations -> full N days

        sort(D.begin(), D.end());

        // Augment with boundaries 0 and N + 1
        vector<long long> days;
        days.reserve(M + 2);
        days.push_back(0);
        for (long long d : D) days.push_back(d);
        days.push_back(N + 1);

        long long maxDays = 0;

        // Slide window of size K (canceling K obligations from i to i + K - 1)
        for (size_t i = 1; i + K < days.size(); i++) {
            long long leftBound = days[i - 1];
            long long rightBound = days[i + K];

            long long vacation = rightBound - leftBound - 1;
            maxDays = max(maxDays, vacation);
        }

        return maxDays;
    }
};

int main() {
    MaxConsecutiveVacation solver;

    vector<long long> D = {3, 5, 8};
    cout << "Max Vacation Days: " << solver.maxVacationDays(10, 3, 1, D) << " (Expected: 5)\n";

    return 0;
}
