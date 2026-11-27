#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    long long maxSumParityAndDistance(const vector<int>& nums, int dist) {
        int n = nums.size();
        // best[i][p]: max non-negative sum in prefix [0..i] ending with parity p (0=even, 1=odd)
        vector<vector<long long>> best(n, vector<long long>(2, 0));

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                best[i][0] = best[i - 1][0];
                best[i][1] = best[i - 1][1];
            }

            int p = abs(nums[i]) % 2;
            long long prevBest = (i - dist >= 0) ? best[i - dist][1 - p] : 0;
            long long candidate = nums[i] + prevBest;

            best[i][p] = max(best[i][p], candidate);
            ans = max(ans, best[i][p]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.maxSumParityAndDistance({2, 5, 4, 3, 6}, 2) == 11);
    assert(sol.maxSumParityAndDistance({4, 2, 6, 8}, 2) == 8);
    assert(sol.maxSumParityAndDistance({1, 2, 3, 4, 5}, 1) == 15); // 1+2+3+4+5 all alternate parity!
    cout << "11_max_sum_parity_and_distance passed all tests!\n";
    return 0;
}
