#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    long long countBoundedCoinsWithGap(const vector<int>& coins, const vector<int>& cnt, int amount, int D) {
        if (amount == 0) return 1;
        int n = coins.size();

        vector<pair<int, int>> items(n);
        for (int i = 0; i < n; i++) items[i] = {coins[i], cnt[i]};
        sort(items.begin(), items.end());

        // pref[i + 1][s]: sum of ways using coins among 0..i to sum to s
        vector<vector<long long>> pref(n + 1, vector<long long>(amount + 1, 0));

        for (int i = 0; i < n; i++) {
            int coin = items[i].first;
            int limit = items[i].second;

            // Find how many earlier sorted coins have value <= coin - D
            int prevIdx = 0;
            for (int j = 0; j < i; j++) {
                if (items[j].first <= coin - D) prevIdx = j + 1;
                else break;
            }

            vector<long long> curWays(amount + 1, 0);
            for (int c = 1; c <= limit && c * coin <= amount; c++) {
                int add = c * coin;
                // Only this coin
                curWays[add] = (curWays[add] + 1) % MOD;
                // Combined with earlier valid denominations (gap >= D)
                if (prevIdx > 0) {
                    for (int s = add + 1; s <= amount; s++) {
                        curWays[s] = (curWays[s] + pref[prevIdx][s - add]) % MOD;
                    }
                }
            }

            for (int s = 0; s <= amount; s++) {
                pref[i + 1][s] = (pref[i][s] + curWays[s]) % MOD;
            }
        }

        return pref[n][amount];
    }
};

int main() {
    Solution sol;
    // Only 1+4=5 is valid (|2-1| = 1 < 2 rejects 1+2+2)
    assert(sol.countBoundedCoinsWithGap({1, 2, 4}, {2, 2, 2}, 5, 2) == 1);
    // For amount=4, D=2: {4} and {2,2} -> 2 ways
    assert(sol.countBoundedCoinsWithGap({1, 2, 4}, {2, 2, 2}, 4, 2) == 2);
    // Standard bounded coin change when D=0
    assert(sol.countBoundedCoinsWithGap({1, 2, 5}, {1, 2, 1}, 5, 0) == 2); // {5}, {1+2+2}
    cout << "20_bounded_coin_change_with_scarcity passed all tests!\n";
    return 0;
}
