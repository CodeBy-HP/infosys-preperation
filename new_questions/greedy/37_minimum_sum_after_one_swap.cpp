#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    long long minSumAfterOneSwap(const vector<int>& A, int K, int D) {
        int n = A.size();
        if (1LL + 1LL * (K - 1) * D > n) return -1;

        multiset<int> outside(A.begin(), A.end());
        long long globalMin = LLONG_MAX;

        for (int rem = 0; rem < D; rem++) {
            vector<int> chain;
            for (int idx = rem; idx < n; idx += D) {
                chain.push_back(A[idx]);
            }
            if (static_cast<int>(chain.size()) < K) continue;

            multiset<int> inside;
            long long winSum = 0;

            for (int i = 0; i < static_cast<int>(chain.size()); i++) {
                // Add chain[i] into inside, remove from outside
                inside.insert(chain[i]);
                outside.erase(outside.find(chain[i]));
                winSum += chain[i];

                // Remove outdated chain[i - K]
                if (i >= K) {
                    int outVal = chain[i - K];
                    inside.erase(inside.find(outVal));
                    outside.insert(outVal);
                    winSum -= outVal;
                }

                if (i >= K - 1) {
                    long long cand = winSum;
                    if (!outside.empty()) {
                        int maxIn = *inside.rbegin();
                        int minOut = *outside.begin();
                        if (minOut < maxIn) {
                            cand = winSum - maxIn + minOut;
                        }
                    }
                    globalMin = min(globalMin, cand);
                }
            }

            // Restore remaining elements of current chain back to outside for next rem
            for (int i = static_cast<int>(chain.size()) - K; i < static_cast<int>(chain.size()); i++) {
                if (i >= 0) {
                    inside.erase(inside.find(chain[i]));
                    outside.insert(chain[i]);
                }
            }
        }

        return globalMin;
    }
};

int main() {
    Solution sol;
    assert(sol.minSumAfterOneSwap({10, 2, 8, 1, 9, 4}, 3, 2) == 7);
    assert(sol.minSumAfterOneSwap({5, 1, 6, 7}, 2, 2) == 6);
    assert(sol.minSumAfterOneSwap({10, 20, 30, 1}, 2, 1) == 11); // [10, 20] swap 20<->1 => 11
    cout << "37_minimum_sum_after_one_swap passed all tests!\n";
    return 0;
}
