#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class TaskScheduler {
public:
    // =========================================================================
    // 1. Greedy Simulation Approach (Max-Heap + Cooldown Queue)
    // Always schedule the task with the highest remaining frequency.
    // Time Complexity: O(Total Time * log 26) = O(Total Time)
    // Space Complexity: O(1) (Heap and queue sizes are at most 26)
    // =========================================================================
    int leastIntervalSimulation(const vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        for (char t : tasks) {
            counts[t - 'A']++;
        }

        priority_queue<int> maxHeap;
        for (int c : counts) {
            if (c > 0) maxHeap.push(c);
        }

        // Stores {remaining_frequency, unlock_time}
        queue<pair<int, int>> cooldownQueue;
        int currentTime = 0;

        while (!maxHeap.empty() || !cooldownQueue.empty()) {
            currentTime++;

            if (!maxHeap.empty()) {
                int freq = maxHeap.top();
                maxHeap.pop();
                freq--;

                if (freq > 0) {
                    cooldownQueue.push({freq, currentTime + n});
                }
            }
            // If heap is empty, CPU sits idle this cycle

            if (!cooldownQueue.empty() && cooldownQueue.front().second == currentTime) {
                maxHeap.push(cooldownQueue.front().first);
                cooldownQueue.pop();
            }
        }

        return currentTime;
    }

    // =========================================================================
    // 2. Closed-Form Mathematical Approach
    // Formula: max(tasks.size(), (max_freq - 1) * (n + 1) + count_max)
    // Time Complexity: O(N)
    // Space Complexity: O(1) (26-element array)
    // =========================================================================
    int leastIntervalMath(const vector<char>& tasks, int n) {
        vector<int> counts(26, 0);
        int maxFreq = 0;
        int countMax = 0;

        for (char t : tasks) {
            counts[t - 'A']++;
            if (counts[t - 'A'] > maxFreq) {
                maxFreq = counts[t - 'A'];
                countMax = 1;
            } else if (counts[t - 'A'] == maxFreq) {
                countMax++;
            }
        }

        int frameSize = (maxFreq - 1) * (n + 1) + countMax;
        return max(frameSize, (int)tasks.size());
    }
};

int main() {
    TaskScheduler solver;

    vector<char> tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    cout << "Test 1 [\"A\",\"A\",\"A\",\"B\",\"B\",\"B\"], n = 2:\n";
    cout << "  Simulation: " << solver.leastIntervalSimulation(tasks1, n1) << "\n";
    cout << "  Math:       " << solver.leastIntervalMath(tasks1, n1) << " (Expected: 8)\n";

    vector<char> tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;
    cout << "Test 2 [\"A\",\"C\",\"A\",\"B\",\"D\",\"B\"], n = 1:\n";
    cout << "  Math:       " << solver.leastIntervalMath(tasks2, n2) << " (Expected: 6)\n";

    return 0;
}

