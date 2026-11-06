#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class MinCostCutStick {
public:
    static int minCost(int n, std::vector<int>& cuts) {
        // Augment with boundaries 0 and n
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, 0));

        // Interval DP by chain length len = 2, 3, ...
        for (int len = 2; len < m; ++len) {
            for (int i = 0; i < m - len; ++i) {
                int j = i + len;
                int minCost = 1e9;
                for (int k = i + 1; k < j; ++k) {
                    minCost = std::min(minCost, dp[i][k] + dp[k][j]);
                }
                dp[i][j] = (cuts[j] - cuts[i]) + minCost;
            }
        }
        return dp[0][m - 1];
    }
};

int main() {
    std::vector<int> c1 = {1, 3, 4, 5};
    assert(MinCostCutStick::minCost(7, c1) == 16);

    std::vector<int> c2 = {5, 6, 1, 4, 2};
    assert(MinCostCutStick::minCost(9, c2) == 22);

    std::cout << "All Minimum Cost to Cut a Stick tests passed successfully!\n";
    return 0;
}

