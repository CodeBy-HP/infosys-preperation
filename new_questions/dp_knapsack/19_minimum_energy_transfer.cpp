#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long INF = 1e15;

public:
    // Optimal O(K * N) Bounded Knapsack with Activation Cost via Monotonic Deque
    long long minEnergyTransfer(int N, const vector<int>& d, const vector<int>& cnt) {
        int K = d.size();
        // dp[e] = min cost to transfer exactly e units (capped at N for >= N)
        vector<long long> dp(N + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < K; i++) {
            int step = d[i];
            int limit = cnt[i];
            if (limit <= 0) continue;

            vector<long long> nextDp = dp;

            // If we reach >= N in one channel jump, check direct jumps from states e < N
            // Exact optimization over modulo classes r in [0, min(step - 1, N)]
            if (step >= N) {
                // Using channel i just once gives >= N energy for cost d[i] + 1
                nextDp[N] = min(nextDp[N], dp[0] + step + 1);
                for (int e = 1; e <= N; e++) {
                    nextDp[N] = min(nextDp[N], dp[e] + step + 1);
                }
            } else {
                // Monotonic deque for exact states e in [0..N-1], plus handling overflow to N
                for (int rem = 0; rem < step; rem++) {
                    deque<pair<int, long long>> dq; // {q_index, dp[q*step + rem] - q}
                    for (int q = 0; q * step + rem <= N; q++) {
                        int e = q * step + rem;

                        while (!dq.empty() && q - dq.front().first > limit) {
                            dq.pop_front();
                        }

                        if (!dq.empty()) {
                            // Cost = prev_dp + activation(step) + (q - prev_q) * 1
                            long long cand = dq.front().second + step + q;
                            nextDp[e] = min(nextDp[e], cand);
                        }

                        if (dp[e] < INF) {
                            long long val = dp[e] - q;
                            while (!dq.empty() && dq.back().second >= val) {
                                dq.pop_back();
                            }
                            dq.push_back({q, val});
                        }
                    }
                }

                // Also allow overshooting N from any state e < N using c <= limit uses
                for (int e = 0; e < N; e++) {
                    if (dp[e] >= INF) continue;
                    int needed = (N - e + step - 1) / step;
                    if (needed <= limit) {
                        nextDp[N] = min(nextDp[N], dp[e] + step + needed);
                    }
                }
            }

            dp.swap(nextDp);
        }

        return dp[N] >= INF ? -1 : dp[N];
    }
};

int main() {
    Solution sol;
    assert(sol.minEnergyTransfer(6, {2, 5}, {3, 1}) == 5);
    assert(sol.minEnergyTransfer(10, {3}, {2}) == -1);
    assert(sol.minEnergyTransfer(7, {2, 5}, {3, 1}) == 9); // 1*2 (cost 3) + 1*5 (cost 6) = 9
    cout << "19_minimum_energy_transfer passed all tests!\n";
    return 0;
}
