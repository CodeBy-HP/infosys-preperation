#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(const vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        int target = totalSum / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int stone : stones) {
            for (int s = target; s >= stone; s--) {
                if (dp[s - stone]) {
                    dp[s] = true;
                }
            }
        }

        for (int s = target; s >= 0; s--) {
            if (dp[s]) {
                return totalSum - 2 * s;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    assert(sol.lastStoneWeightII({2, 7, 4, 1, 8, 1}) == 1);
    assert(sol.lastStoneWeightII({31, 26, 33, 21, 40}) == 5);
    cout << "21_last_stone_weight_ii passed all tests!\n";
    return 0;
}
