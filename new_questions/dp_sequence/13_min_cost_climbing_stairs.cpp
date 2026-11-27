#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        int prev2 = 0, prev1 = 0;
        int n = cost.size();

        for (int i = 2; i <= n; i++) {
            int curr = min(prev1 + cost[i - 1], prev2 + cost[i - 2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    Solution sol;
    assert(sol.minCostClimbingStairs({10, 15, 20}) == 15);
    assert(sol.minCostClimbingStairs({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}) == 6);
    cout << "13_min_cost_climbing_stairs passed all tests!\n";
    return 0;
}
