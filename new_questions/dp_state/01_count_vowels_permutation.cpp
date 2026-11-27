#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    // Approach 1: O(N) Time, O(1) Space State-Machine DP
    int countVowelPermutation(int n) {
        long long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int step = 2; step <= n; step++) {
            long long na = (e + i + u) % MOD;
            long long ne = (a + i) % MOD;
            long long ni = (e + o) % MOD;
            long long no = i % MOD;
            long long nu = (i + o) % MOD;
            a = na; e = ne; i = ni; o = no; u = nu;
        }
        return (a + e + i + o + u) % MOD;
    }

    // Approach 2: Matrix Exponentiation for massive N (up to 10^18)
    int countVowelPermutationMatrix(long long n) {
        if (n == 1) return 5;
        using Mat = vector<vector<long long>>;
        auto mul = [&](const Mat& A, const Mat& B) {
            Mat C(5, vector<long long>(5, 0));
            for (int r = 0; r < 5; r++)
                for (int k = 0; k < 5; k++)
                    if (A[r][k])
                        for (int c = 0; c < 5; c++)
                            C[r][c] = (C[r][c] + A[r][k] * B[k][c]) % MOD;
            return C;
        };

        Mat T = {
            {0, 1, 1, 0, 1}, // -> a from e, i, u
            {1, 0, 1, 0, 0}, // -> e from a, i
            {0, 1, 0, 1, 0}, // -> i from e, o
            {0, 0, 1, 0, 0}, // -> o from i
            {0, 0, 1, 1, 0}  // -> u from i, o
        };
        Mat res(5, vector<long long>(5, 0));
        for (int k = 0; k < 5; k++) res[k][k] = 1;

        long long p = n - 1;
        while (p > 0) {
            if (p & 1) res = mul(res, T);
            T = mul(T, T);
            p >>= 1;
        }

        long long total = 0;
        for (int r = 0; r < 5; r++)
            for (int c = 0; c < 5; c++)
                total = (total + res[r][c]) % MOD;
        return total;
    }
};

int main() {
    Solution sol;
    assert(sol.countVowelPermutation(1) == 5);
    assert(sol.countVowelPermutation(2) == 10);
    assert(sol.countVowelPermutation(5) == 68);
    assert(sol.countVowelPermutationMatrix(5) == 68);
    cout << "01_count_vowels_permutation passed all tests!\n";
    return 0;
}
