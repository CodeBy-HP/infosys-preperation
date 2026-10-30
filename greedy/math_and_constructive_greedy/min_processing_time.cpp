#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinimumProcessingTime {
public:
    // =========================================================================
    // 1. Dual-Sort Greedy Approach (Processors Ascending, Tasks Descending)
    // Pair earliest available processor with longest duration tasks.
    // Time Complexity: O(N log N + M log M), where M = 4 * N
    // Space Complexity: O(1)
    // =========================================================================
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());

        int maxTime = 0;
        int n = processorTime.size();

        for (int i = 0; i < n; i++) {
            // Because tasks are sorted descending, tasks[i * 4] is the bottleneck task
            int processorFinish = processorTime[i] + tasks[i * 4];
            maxTime = max(maxTime, processorFinish);
        }

        return maxTime;
    }

    // =========================================================================
    // 2. Dual Ascending Sort (Matching Processor i with Task [4*(n - 1 - i) + 3])
    // Time Complexity: O(N log N + M log M)
    // Space Complexity: O(1)
    // =========================================================================
    int minProcessingTimeAscending(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end());

        int maxTime = 0;
        int n = processorTime.size();

        for (int i = 0; i < n; i++) {
            // The bottleneck task for processor i is at index: 4 * (n - 1 - i) + 3
            int taskIdx = 4 * (n - 1 - i) + 3;
            maxTime = max(maxTime, processorTime[i] + tasks[taskIdx]);
        }

        return maxTime;
    }
};

int main() {
    MinimumProcessingTime solver;

    vector<int> pTime1 = {8, 10};
    vector<int> tasks1 = {2, 2, 3, 1, 8, 7, 4, 5};
    cout << "Test 1 [8, 10]:\n";
    cout << "  Dual-Sort: " << solver.minProcessingTime(pTime1, tasks1) << " (Expected: 16)\n";

    vector<int> pTime2 = {10, 20};
    vector<int> tasks2 = {2, 3, 1, 2, 5, 8, 4, 3};
    cout << "Test 2 [10, 20]:\n";
    cout << "  Dual-Sort: " << solver.minProcessingTime(pTime2, tasks2) << " (Expected: 23)\n";

    return 0;
}

