#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int combinationSum4(const vector<int>& nums, int target) {
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int s = 1; s <= target; s++) {
            for (int num : nums) {
                if (s >= num) {
                    dp[s] += dp[s - num];
                }
            }
        }
        return static_cast<int>(dp[target]);
    }
};

int main() {
    Solution sol;
    assert(sol.combinationSum4({1, 2, 3}, 4) == 7);
    assert(sol.combinationSum4({9}, 3) == 0);
    cout << "23_combination_sum_iv passed all tests!\n";
    return 0;
}
