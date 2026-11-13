#include <iostream>
#include <vector>
#include <cassert>

class CoinChangeII {
public:
    // Approach 1: 2D Tabulation - O(N * amount) Time, O(N * amount) Space
    static int change2D(int amount, const std::vector<int>& coins) {
        int n = coins.size();
        std::vector<std::vector<unsigned long long>> dp(n, std::vector<unsigned long long>(amount + 1, 0));

        for (int t = 0; t <= amount; ++t) {
            if (t % coins[0] == 0) dp[0][t] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int t = 0; t <= amount; ++t) {
                unsigned long long notTake = dp[i - 1][t];
                unsigned long long take = (coins[i] <= t) ? dp[i][t - coins[i]] : 0;
                dp[i][t] = notTake + take;
            }
        }
        return dp[n - 1][amount];
    }

    // Approach 2: 1D Forward Unbounded - O(N * amount) Time, O(amount) Space
    static int changeOptimized(int amount, const std::vector<int>& coins) {
        std::vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int a = coin; a <= amount; ++a) {
                dp[a] += dp[a - coin];
            }
        }
        return dp[amount];
    }
};

int main() {
    std::vector<int> c1 = {1, 2, 5};
    int a1 = 5;
    assert(CoinChangeII::change2D(a1, c1) == 4);
    assert(CoinChangeII::changeOptimized(a1, c1) == 4);

    std::vector<int> c2 = {2};
    int a2 = 3;
    assert(CoinChangeII::change2D(a2, c2) == 0);
    assert(CoinChangeII::changeOptimized(a2, c2) == 0);

    std::vector<int> c3 = {10};
    int a3 = 10;
    assert(CoinChangeII::change2D(a3, c3) == 1);
    assert(CoinChangeII::changeOptimized(a3, c3) == 1);

    std::cout << "All Coin Change II tests passed successfully!\n";
    return 0;
}

