#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Optimal Stratified SOS DP for Pairs (i < j) with (A[i]&A[j]==0) and ((A[i]|A[j])%3==0)
    long long countPerfectPairsSOS(const vector<int>& A) {
        if (A.empty()) return 0;
        int maxVal = *max_element(A.begin(), A.end());
        int B = 1;
        while ((1 << B) <= maxVal) B++;
        int limit = 1 << B;
        int fullMask = limit - 1;

        // sos[r][mask] = count of elements y in A with y % 3 == r and (y & mask) == y
        vector<vector<long long>> sos(3, vector<long long>(limit, 0));
        for (int x : A) {
            sos[x % 3][x]++;
        }

        for (int r = 0; r < 3; r++) {
            for (int bit = 0; bit < B; bit++) {
                for (int mask = 0; mask < limit; mask++) {
                    if (mask & (1 << bit)) {
                        sos[r][mask] += sos[r][mask ^ (1 << bit)];
                    }
                }
            }
        }

        long long orderedPairs = 0;
        for (int x : A) {
            int comp = fullMask ^ x;
            int needRem = (3 - (x % 3)) % 3;
            orderedPairs += sos[needRem][comp];
            if (x == 0) orderedPairs--; // Exclude self-pair (0, 0) since i != j
        }

        return orderedPairs / 2;
    }

    // Brute Force Reference for Verification
    long long countPerfectPairsBrute(const vector<int>& A) {
        long long cnt = 0;
        for (size_t i = 0; i < A.size(); i++) {
            for (size_t j = i + 1; j < A.size(); j++) {
                if ((A[i] & A[j]) == 0 && ((A[i] | A[j]) % 3 == 0)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    assert(sol.countPerfectPairsSOS({1, 2, 4, 5}) == 2);
    assert(sol.countPerfectPairsSOS({0, 0, 3, 6}) == sol.countPerfectPairsBrute({0, 0, 3, 6}));
    assert(sol.countPerfectPairsSOS({1, 2, 4, 8, 16, 3, 0}) == sol.countPerfectPairsBrute({1, 2, 4, 8, 16, 3, 0}));
    cout << "50_perfect_combinations_bitmask passed all tests!\n";
    return 0;
}
