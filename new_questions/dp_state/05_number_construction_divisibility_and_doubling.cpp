#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr int MOD = 1000000007;

public:
    // Variant 1: Classic Infosys PYQ (a[i+1] % a[i] == 0) using O(k * n log n) push-DP
    int countDivisibleArrays(int n, int k, int mod = 10000) {
        vector<int> dp(n + 1, 1);
        dp[0] = 0;

        for (int len = 2; len <= k; len++) {
            vector<int> nextDp(n + 1, 0);
            for (int v = 1; v <= n; v++) {
                if (dp[v] == 0) continue;
                for (int mult = v; mult <= n; mult += v) {
                    nextDp[mult] = (nextDp[mult] + dp[v]) % mod;
                }
            }
            dp.swap(nextDp);
        }

        int total = 0;
        for (int v = 1; v <= n; v++) {
            total = (total + dp[v]) % mod;
        }
        return total;
    }

    // Variant 2: Restricted Doubling Sequence (a[i+1] == a[i] or a[i+1] == 2 * a[i])
    int countDoublingArrays(int n, int k) {
        vector<int> dp(n + 1, 1);
        dp[0] = 0;

        for (int len = 2; len <= k; len++) {
            vector<int> nextDp(n + 1, 0);
            for (int v = 1; v <= n; v++) {
                nextDp[v] = (nextDp[v] + dp[v]) % MOD;
                if (2 * v <= n) {
                    nextDp[2 * v] = (nextDp[2 * v] + dp[v]) % MOD;
                }
            }
            dp.swap(nextDp);
        }

        int total = 0;
        for (int v = 1; v <= n; v++) {
            total = (total + dp[v]) % MOD;
        }
        return total;
    }
};

int main() {
    Solution sol;
    assert(sol.countDivisibleArrays(2, 1) == 2);
    assert(sol.countDivisibleArrays(2, 2) == 3);
    assert(sol.countDivisibleArrays(3, 2) == 5); // [1,1],[1,2],[1,3],[2,2],[3,3]
    assert(sol.countDoublingArrays(4, 2) == 6);
    cout << "05_number_construction_divisibility_and_doubling passed all tests!\n";
    return 0;
}
