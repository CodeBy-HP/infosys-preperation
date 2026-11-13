#include <iostream>

class Solution {
public:
    // Approach 1: O(1) Bitwise Parity Formula
    int kthGrammarBitwise(int n, int k) {
        // Number of set bits in (k - 1) determines the symbol
        return __builtin_popcount(k - 1) & 1;
    }

    // Approach 2: Recursive Parent Tracing O(N)
    int kthGrammarRecursive(int n, int k) {
        if (n == 1) return 0;
        int parent = kthGrammarRecursive(n - 1, (k + 1) / 2);
        if (k % 2 == 1) {
            return parent;      // Odd position matches parent
        } else {
            return 1 - parent;  // Even position is inverted
        }
    }
};

int main() {
    Solution sol;
    std::cout << "kthGrammar(n=1, k=1): " << sol.kthGrammarBitwise(1, 1) << " (Expected: 0)\n";
    std::cout << "kthGrammar(n=2, k=1): " << sol.kthGrammarBitwise(2, 1) << " (Expected: 0)\n";
    std::cout << "kthGrammar(n=2, k=2): " << sol.kthGrammarBitwise(2, 2) << " (Expected: 1)\n";
    std::cout << "kthGrammar(n=4, k=5): " << sol.kthGrammarBitwise(4, 5) << " (Expected: 1)\n";
    std::cout << "kthGrammar(n=4, k=7): " << sol.kthGrammarBitwise(4, 7) << " (Expected: 0)\n";

    return 0;
}
