#include <iostream>
#include <vector>

using namespace std;

class GasStation {
public:
    // =========================================================================
    // 1. Optimal Greedy Approach (Single Pass with Greedy Leap)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int canCompleteCircuitGreedy(const vector<int>& gas, const vector<int>& cost) {
        int totalGas = 0;
        int totalCost = 0;
        int currentTank = 0;
        int startIndex = 0;

        for (size_t i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];

            currentTank += gas[i] - cost[i];

            // If local tank drops below 0, station 'i' and all previous candidates fail
            if (currentTank < 0) {
                startIndex = i + 1; // Greedily leap to the next station
                currentTank = 0;    // Reset tank
            }
        }

        // If total gas is less than total cost, complete circuit is impossible
        return (totalGas < totalCost) ? -1 : startIndex;
    }

    // =========================================================================
    // 2. Brute-Force Simulation Approach (Testing Each Starting Index)
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)
    // =========================================================================
    int canCompleteCircuitBruteForce(const vector<int>& gas, const vector<int>& cost) {
        int n = gas.size();

        for (int start = 0; start < n; start++) {
            int tank = 0;
            bool possible = true;

            for (int step = 0; step < n; step++) {
                int curr = (start + step) % n;
                tank += gas[curr] - cost[curr];
                if (tank < 0) {
                    possible = false;
                    break;
                }
            }

            if (possible) return start;
        }

        return -1;
    }
};

int main() {
    GasStation solver;

    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Test 1:\n";
    cout << "  Greedy:      " << solver.canCompleteCircuitGreedy(gas1, cost1) << "\n";
    cout << "  Brute-Force: " << solver.canCompleteCircuitBruteForce(gas1, cost1) << " (Expected: 3)\n";

    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Test 2:\n";
    cout << "  Greedy:      " << solver.canCompleteCircuitGreedy(gas2, cost2) << " (Expected: -1)\n";

    return 0;
}

