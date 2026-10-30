#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

class MinStepsToClearArray {
public:
    // =========================================================================
    // 1. Optimal Closed-Form Mathematical Approach
    // Formula: max(max_freq, (N + 1) / 2)
    // Time Complexity: O(N)
    // Space Complexity: O(U), where U is number of unique elements
    // =========================================================================
    int minStepsMath(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        unordered_map<int, int> freq;
        int maxFreq = 0;

        for (int x : nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }

        int halfRoundedUp = (n + 1) / 2;
        return max(maxFreq, halfRoundedUp);
    }

    // =========================================================================
    // 2. Max-Heap Simulation Approach
    // Always pair elements from the two most frequent piles.
    // Time Complexity: O(N log U)
    // Space Complexity: O(U)
    // =========================================================================
    int minStepsHeapSimulation(const vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();

        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        priority_queue<int> maxHeap;
        for (auto& [val, count] : freq) {
            maxHeap.push(count);
        }

        int steps = 0;

        while (maxHeap.size() > 1) {
            int first = maxHeap.top(); maxHeap.pop();
            int second = maxHeap.top(); maxHeap.pop();

            // Pair 1 element from each pile
            steps++;
            first--;
            second--;

            if (first > 0) maxHeap.push(first);
            if (second > 0) maxHeap.push(second);
        }

        // Any leftover elements in the single remaining pile must be removed 1 by 1
        if (!maxHeap.empty()) {
            steps += maxHeap.top();
        }

        return steps;
    }
};

int main() {
    MinStepsToClearArray solver;

    vector<int> test1 = {1, 2};
    cout << "Test 1 [1, 2]:\n";
    cout << "  Math:       " << solver.minStepsMath(test1) << "\n";
    cout << "  Simulation: " << solver.minStepsHeapSimulation(test1) << " (Expected: 1)\n";

    vector<int> test2 = {2, 2};
    cout << "Test 2 [2, 2]:\n";
    cout << "  Math:       " << solver.minStepsMath(test2) << "\n";
    cout << "  Simulation: " << solver.minStepsHeapSimulation(test2) << " (Expected: 2)\n";

    vector<int> test3 = {2, 2, 3, 3, 1};
    cout << "Test 3 [2, 2, 3, 3, 1]:\n";
    cout << "  Math:       " << solver.minStepsMath(test3) << "\n";
    cout << "  Simulation: " << solver.minStepsHeapSimulation(test3) << " (Expected: 3)\n";

    return 0;
}

