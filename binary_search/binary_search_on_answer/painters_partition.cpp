#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class PaintersPartition {
private:
    // Helper to count how many painters are needed if max workload is maxAllowed
    int countPaintersNeeded(const vector<int>& boards, long long maxAllowed) {
        int painters = 1;
        long long currentWorkload = 0;

        for (int length : boards) {
            if (currentWorkload + length <= maxAllowed) {
                currentWorkload += length;
            } else {
                painters++;
                currentWorkload = length;
            }
        }
        return painters;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search on Answer
    // Time Complexity: O(N * log(sum(boards)))
    // Space Complexity: O(1)
    // =========================================================================
    long long findLargestMinDistance(const vector<int>& boards, int k) {
        long long left = *max_element(boards.begin(), boards.end());
        long long right = accumulate(boards.begin(), boards.end(), 0LL);
        long long ans = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            int paintersNeeded = countPaintersNeeded(boards, mid);

            if (paintersNeeded <= k) {
                ans = mid;        // Feasible, try to minimize workload further
                right = mid - 1;
            } else {
                left = mid + 1;   // Exceeded allowed painters, increase workload limit
            }
        }
        return ans;
    }
};

int main() {
    PaintersPartition solver;

    vector<int> boards1 = {10, 20, 30, 40};
    int k1 = 2;
    cout << "Test 1: " << solver.findLargestMinDistance(boards1, k1) << " (Expected: 60)\n";

    vector<int> boards2 = {5, 5, 5, 5};
    int k2 = 2;
    cout << "Test 2: " << solver.findLargestMinDistance(boards2, k2) << " (Expected: 10)\n";

    return 0;
}

