#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>
#include <chrono>

class KSetBitsCombinations {
public:
    // =========================================================================
    // Approach 1: Brute Force Power Set Filtering
    // Checks every number from 0 to 2^n - 1.
    // Time Complexity: O(2^N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    std::vector<uint32_t> generateBruteForce(int n, int k) {
        std::vector<uint32_t> result;
        if (k < 0 || k > n) return result;

        uint64_t limit = 1ULL << n;
        for (uint64_t mask = 0; mask < limit; ++mask) {
            if (__builtin_popcountll(mask) == k) {
                result.push_back((uint32_t)mask);
            }
        }
        return result;
    }

    // =========================================================================
    // Approach 2: Recursive Backtracking (Branching on Bit Positions)
    // Time Complexity: O(C(N, K)) because of prunning
    // Space Complexity: O(N) recursion stack
    // =========================================================================
    std::vector<uint32_t> generateBacktracking(int n, int k) {
        std::vector<uint32_t> result;
        if (k < 0 || k > n) return result;

        auto dfs = [&](auto& self, int pos, int bitsLeft, uint32_t currentMask) -> void {
            if (bitsLeft == 0) {
                result.push_back(currentMask);
                return;
            }
            if (pos >= n || (n - pos) < bitsLeft) {
                return; // Prune if not enough remaining positions
            }

            // Choice 1: Include bit at position pos
            self(self, pos + 1, bitsLeft - 1, currentMask | (1U << pos));

            // Choice 2: Skip bit at position pos
            self(self, pos + 1, bitsLeft, currentMask);
        };

        dfs(dfs, 0, k, 0);
        return result;
    }

    // =========================================================================
    // Approach 3: Gosper's Hack (Optimal In-Place Next Bit Permutation)
    // Generates strictly valid masks in lexicographically ascending order.
    // Time Complexity: O(C(N, K)) strictly
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    std::vector<uint32_t> generateGospersHack(int n, int k) {
        std::vector<uint32_t> result;
        if (k < 0 || k > n) return result;
        if (k == 0) {
            result.push_back(0);
            return result;
        }

        // Smallest integer with exactly k set bits (e.g. k=3 -> 000111 in binary)
        uint64_t mask = (1ULL << k) - 1ULL;
        uint64_t limit = 1ULL << n;

        while (mask < limit) {
            result.push_back((uint32_t)mask);

            // Step 1: Isolate the lowest set bit
            uint64_t c = mask & -mask;

            // Step 2: Ripple carry addition: flips lowest block of 1s and sets bit to left
            uint64_t r = mask + c;

            // Step 3: Reposition remaining ones to the least significant positions
            // ((r ^ mask) >> 2) / c shifts the run down and discards the two extra bits
            mask = (((r ^ mask) >> 2) / c) | r;
        }

        return result;
    }

    // Helper: Compute the single next lexicographical integer with same set bits
    uint32_t nextPermutation(uint32_t mask) {
        if (mask == 0) return 0;
        uint64_t c = mask & -mask;
        uint64_t r = mask + c;
        return (uint32_t)((((r ^ mask) >> 2) / c) | r);
    }
};

int main() {
    KSetBitsCombinations solver;

    std::cout << "=========================================================\n";
    std::cout << "TEST 1: Small Scale (N = 4, K = 2)\n";
    std::cout << "=========================================================\n";
    int n1 = 4, k1 = 2;

    auto brute = solver.generateBruteForce(n1, k1);
    auto gospers = solver.generateGospersHack(n1, k1);

    std::cout << "Gosper's Hack Output (" << gospers.size() << " combinations):\n";
    for (uint32_t m : gospers) {
        std::cout << "Decimal: " << m << "\tBinary (4-bit): " 
                  << std::bitset<4>(m) << "\n";
    }

    std::cout << "Match Brute Force: " 
              << (brute == gospers ? "PASSED (Identical)" : "FAILED") << "\n\n";

    std::cout << "=========================================================\n";
    std::cout << "TEST 2: Edge Cases (K = 0, K = N)\n";
    std::cout << "=========================================================\n";
    auto kZero = solver.generateGospersHack(5, 0);
    std::cout << "N=5, K=0 count: " << kZero.size() 
              << " (Expected: 1, Value: " << kZero[0] << ")\n";

    auto kAll = solver.generateGospersHack(5, 5);
    std::cout << "N=5, K=5 count: " << kAll.size() 
              << " (Expected: 1, Value: " << kAll[0] << " / 11111)\n\n";

    std::cout << "=========================================================\n";
    std::cout << "TEST 3: Efficiency Comparison (N = 22, K = 4)\n";
    std::cout << "=========================================================\n";
    int n3 = 22, k3 = 4; // C(22, 4) = 7,315 vs 2^22 = 4,194,304

    auto startG = std::chrono::high_resolution_clock::now();
    auto resG = solver.generateGospersHack(n3, k3);
    auto endG = std::chrono::high_resolution_clock::now();
    auto timeG = std::chrono::duration_cast<std::chrono::microseconds>(endG - startG).count();

    auto startB = std::chrono::high_resolution_clock::now();
    auto resB = solver.generateBruteForce(n3, k3);
    auto endB = std::chrono::high_resolution_clock::now();
    auto timeB = std::chrono::duration_cast<std::chrono::microseconds>(endB - startB).count();

    std::cout << "Total combinations C(22, 4): " << resG.size() << " (Expected: 7315)\n";
    std::cout << "Gosper's Hack Time: " << timeG << " microseconds\n";
    std::cout << "Brute Force Time:   " << timeB << " microseconds\n";
    std::cout << "Speedup Factor:     " << (double)timeB / (timeG > 0 ? timeG : 1) << "x faster!\n";

    return 0;
}

