#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cassert>

class TaskScheduler {
public:
    // Approach 1: Max-Heap Simulation with Cooldown Queue
    static int leastIntervalHeap(const std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> freq;
        for (char t : tasks) freq[t]++;

        std::priority_queue<int> maxHeap;
        for (auto [ch, count] : freq) {
            maxHeap.push(count);
        }

        // Queue storing {remainingCount, readyTime}
        std::queue<std::pair<int, int>> cooldown;
        int time = 0;

        while (!maxHeap.empty() || !cooldown.empty()) {
            time++;

            if (!cooldown.empty() && cooldown.front().second <= time) {
                maxHeap.push(cooldown.front().first);
                cooldown.pop();
            }

            if (!maxHeap.empty()) {
                int count = maxHeap.top() - 1;
                maxHeap.pop();
                if (count > 0) {
                    cooldown.push({count, time + n + 1});
                }
            }
        }
        return time;
    }

    // Approach 2: Mathematical Closed-Form - O(N) Time, O(1) Space
    static int leastIntervalMath(const std::vector<char>& tasks, int n) {
        std::vector<int> freq(26, 0);
        int maxFreq = 0;
        for (char t : tasks) {
            freq[t - 'A']++;
            maxFreq = std::max(maxFreq, freq[t - 'A']);
        }

        int maxCount = 0;
        for (int f : freq) {
            if (f == maxFreq) maxCount++;
        }

        int minTime = (maxFreq - 1) * (n + 1) + maxCount;
        return std::max(static_cast<int>(tasks.size()), minTime);
    }
};

int main() {
    std::vector<char> t1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    assert(TaskScheduler::leastIntervalHeap(t1, 2) == 8);
    assert(TaskScheduler::leastIntervalMath(t1, 2) == 8);

    std::vector<char> t2 = {'A', 'A', 'A', 'B', 'B', 'B'};
    assert(TaskScheduler::leastIntervalHeap(t2, 0) == 6);
    assert(TaskScheduler::leastIntervalMath(t2, 0) == 6);

    std::cout << "All Task Scheduler tests passed successfully!\n";
    return 0;
}

