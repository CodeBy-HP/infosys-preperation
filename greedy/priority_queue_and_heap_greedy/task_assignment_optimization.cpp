#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>

/**
 * Task Assignment Optimization (Greedy + Max-Heap)
 * 
 * Problem:
 * Given N tasks (difficulty D_i, profit W_i) and M workers (skill S_j).
 * Each worker can perform at most 1 task where S_j >= D_i.
 * Each task can be assigned to at most 1 worker.
 * Maximize total profit.
 * 
 * Time Complexity: O(N log N + M log M + (N + M) log N)
 * Space Complexity: O(N) for priority queue
 */

struct Task {
    int difficulty;
    long long profit;
};

class Solution {
public:
    long long maxTaskAssignmentProfit(std::vector<Task>& tasks, std::vector<int>& workers) {
        // Step 1: Sort tasks by difficulty ascending
        std::sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
            return a.difficulty < b.difficulty;
        });

        // Step 2: Sort workers by skill ascending
        std::sort(workers.begin(), workers.end());

        // Step 3: Max-heap to store profits of all currently eligible tasks
        std::priority_queue<long long> eligible_profits;

        long long total_profit = 0;
        int task_idx = 0;
        int n = static_cast<int>(tasks.size());

        for (int worker_skill : workers) {
            // Push all newly eligible tasks into the max-heap
            while (task_idx < n && tasks[task_idx].difficulty <= worker_skill) {
                eligible_profits.push(tasks[task_idx].profit);
                task_idx++;
            }

            // Greedily assign the highest profit eligible task to this worker
            if (!eligible_profits.empty()) {
                total_profit += eligible_profits.top();
                eligible_profits.pop();
            }
        }

        return total_profit;
    }
};

int main() {
    Solution solver;

    // Test 1: Standard case
    {
        std::vector<Task> tasks = {{2, 40}, {4, 100}, {6, 70}, {8, 60}};
        std::vector<int> workers = {4, 5, 8};
        long long ans = solver.maxTaskAssignmentProfit(tasks, workers);
        std::cout << "Test 1: Expected = 210, Actual = " << ans << std::endl;
        assert(ans == 210);
    }

    // Test 2: Ineligible workers
    {
        std::vector<Task> tasks = {{10, 100}};
        std::vector<int> workers = {2, 3, 5};
        long long ans = solver.maxTaskAssignmentProfit(tasks, workers);
        std::cout << "Test 2: Expected = 0, Actual = " << ans << std::endl;
        assert(ans == 0);
    }

    // Test 3: More workers than tasks
    {
        std::vector<Task> tasks = {{1, 50}, {3, 80}};
        std::vector<int> workers = {2, 5, 10, 15};
        long long ans = solver.maxTaskAssignmentProfit(tasks, workers);
        std::cout << "Test 3: Expected = 130, Actual = " << ans << std::endl;
        assert(ans == 130);
    }

    // Test 4: More tasks than workers
    {
        std::vector<Task> tasks = {{1, 10}, {2, 90}, {2, 100}, {5, 200}};
        std::vector<int> workers = {2, 2};
        // Worker 1 (skill 2) takes 100, Worker 2 (skill 2) takes 90 -> total = 190
        long long ans = solver.maxTaskAssignmentProfit(tasks, workers);
        std::cout << "Test 4: Expected = 190, Actual = " << ans << std::endl;
        assert(ans == 190);
    }

    std::cout << "All Task Assignment Optimization test cases passed successfully!" << std::endl;
    return 0;
}

