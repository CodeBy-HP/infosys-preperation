#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>

/**
 * Maximize XOR Sum (Digit DP on Bits / Greedy Upper Bound)
 * 
 * Problem:
 * Given array A and bound K, find x in [0, K] maximizing sum_{i=1}^N (x ^ A[i]).
 * 
 * Time Complexity: O(N * B + B) where B <= 62
 * Space Complexity: O(B)
 */

class Solution {
private:
    static const int MAX_BITS = 62;
    long long memo[MAX_BITS][2];
    int cnt1[MAX_BITS];
    int cnt0[MAX_BITS];

    long long dfs(int b, bool tight, long long K) {
        if (b < 0) return 0;
        if (memo[b][tight] != -1) return memo[b][tight];

        int limit = tight ? ((K >> b) & 1) : 1;
        long long max_sum = 0;

        for (int bit_val = 0; bit_val <= limit; ++bit_val) {
            long long contribution = (bit_val == 1 ? cnt0[b] : cnt1[b]) * (1LL << b);
            bool next_tight = tight && (bit_val == limit);
            long long res = contribution + dfs(b - 1, next_tight, K);
            if (res > max_sum) {
                max_sum = res;
            }
        }

        return memo[b][tight] = max_sum;
    }

public:
    long long maximizeXorSum(const std::vector<long long>& A, long long K) {
        int n = static_cast<int>(A.size());
        if (n == 0) return 0;

        // Reset state
        std::memset(memo, -1, sizeof(memo));
        std::fill(cnt1, cnt1 + MAX_BITS, 0);
        std::fill(cnt0, cnt0 + MAX_BITS, 0);

        // Precompute bit frequency counts
        for (long long val : A) {
            for (int b = 0; b < MAX_BITS; ++b) {
                if ((val >> b) & 1LL) {
                    cnt1[b]++;
                }
            }
        }
        for (int b = 0; b < MAX_BITS; ++b) {
            cnt0[b] = n - cnt1[b];
        }

        return dfs(MAX_BITS - 1, true, K);
    }
};

int main() {
    Solution solver;

    // Test 1: Standard sample
    {
        std::vector<long long> A = {1, 6, 3};
        long long K = 7;
        long long ans = solver.maximizeXorSum(A, K);
        std::cout << "Test 1: Expected = 14, Actual = " << ans << std::endl;
        assert(ans == 14);
    }

    // Test 2: K = 0 (only x = 0 allowed)
    {
        std::vector<long long> A = {10, 20, 30, 40};
        long long K = 0;
        long long ans = solver.maximizeXorSum(A, K);
        std::cout << "Test 2: Expected = 100, Actual = " << ans << std::endl;
        assert(ans == 100);
    }

    // Test 3: Large constraints
    {
        std::vector<long long> A = {1000000000000LL, 500000000000LL};
        long long K = 1000000000000LL;
        long long ans = solver.maximizeXorSum(A, K);
        assert(ans > 0);
    }

    std::cout << "All Maximize XOR Sum test cases passed successfully!" << std::endl;
    return 0;
}

