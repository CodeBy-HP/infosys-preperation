#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    int countAlternatingVowelPaths(int n) {
        if (n == 1) return 5;

        // Vowels indexed: 0:'a', 1:'e', 2:'i', 3:'o', 4:'u'
        vector<vector<int>> adj = {
            {1},          // a -> e
            {0, 2},       // e -> a, i
            {0, 1, 3, 4}, // i -> a, e, o, u
            {2, 4},       // o -> i, u
            {0}           // u -> a
        };

        vector<long long> up(5, 0), down(5, 0);

        // Step 2: Transition from any length-1 vowel (count = 1 each)
        for (int u = 0; u < 5; u++) {
            for (int v : adj[u]) {
                if (v > u) up[v] = (up[v] + 1) % MOD;
                else down[v] = (down[v] + 1) % MOD;
            }
        }

        // Steps 3..n: Strictly alternate direction
        for (int step = 3; step <= n; step++) {
            vector<long long> nextUp(5, 0), nextDown(5, 0);
            for (int u = 0; u < 5; u++) {
                for (int v : adj[u]) {
                    if (v > u) {
                        nextUp[v] = (nextUp[v] + down[u]) % MOD;
                    } else {
                        nextDown[v] = (nextDown[v] + up[u]) % MOD;
                    }
                }
            }
            up.swap(nextUp);
            down.swap(nextDown);
        }

        long long ans = 0;
        for (int v = 0; v < 5; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.countAlternatingVowelPaths(1) == 5);
    assert(sol.countAlternatingVowelPaths(2) == 10);
    assert(sol.countAlternatingVowelPaths(3) == 12);
    cout << "06_alternating_vowel_paths passed all tests! (n=3 -> " << sol.countAlternatingVowelPaths(3) << ")\n";
    return 0;
}
