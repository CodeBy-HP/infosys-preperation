#include <iostream>
#include <vector>
#include <cassert>

/**
 * Count Paths of Length K in Directed Graph
 * Uses powers of the adjacency matrix: (A^K)[u][v] % (10^9 + 7).
 * Time Complexity: O(V^3 log K)
 * Space Complexity: O(V^2)
 */

class GraphPathCounter {
private:
    static const long long MOD = 1e9 + 7;
    using Matrix = std::vector<std::vector<long long>>;

    static Matrix multiply(const Matrix& A, const Matrix& B, int V) {
        Matrix C(V, std::vector<long long>(V, 0));
        for (int i = 0; i < V; ++i) {
            for (int k = 0; k < V; ++k) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < V; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    static Matrix power(Matrix A, long long p, int V) {
        Matrix res(V, std::vector<long long>(V, 0));
        for (int i = 0; i < V; ++i) res[i][i] = 1;

        while (p > 0) {
            if (p & 1) res = multiply(res, A, V);
            A = multiply(A, A, V);
            p >>= 1;
        }
        return res;
    }

public:
    static long long countPaths(int V, const Matrix& adj, int u, int v, long long K) {
        if (K == 0) {
            return (u == v) ? 1 : 0;
        }

        Matrix AK = power(adj, K, V);
        return AK[u][v];
    }
};

int main() {
    // Test 1: Simple 3-vertex triangle: 0 -> 1 -> 2 -> 0
    int V = 3;
    std::vector<std::vector<long long>> adj = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    // Paths of length 1: 0 -> 1 is 1
    assert(GraphPathCounter::countPaths(V, adj, 0, 1, 1) == 1);
    // Paths of length 2: 0 -> 1 -> 2 is 1
    assert(GraphPathCounter::countPaths(V, adj, 0, 2, 2) == 1);
    // Paths of length 3: 0 -> 1 -> 2 -> 0 is 1
    assert(GraphPathCounter::countPaths(V, adj, 0, 0, 3) == 1);
    // Paths of length 6: 0 -> 0 is 1
    assert(GraphPathCounter::countPaths(V, adj, 0, 0, 6) == 1);

    // Test 2: Huge K = 10^18
    long long huge_K = 1000000000000000000LL;
    long long ans = GraphPathCounter::countPaths(V, adj, 0, (huge_K % 3), huge_K);
    std::cout << "Paths of length 10^18: " << ans << std::endl;
    assert(ans == 1);

    std::cout << "All Graph Path Matrix Exponentiation tests passed successfully!" << std::endl;
    return 0;
}

