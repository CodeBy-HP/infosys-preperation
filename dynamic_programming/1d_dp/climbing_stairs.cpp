#include <iostream>
#include <vector>

class Solution {
public:
    // Approach 1: O(N) Time, O(1) Space State Rolling
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1; // ways to reach step 1
        int prev1 = 2; // ways to reach step 2

        for (int i = 3; i <= n; ++i) {
            int current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }

    // Approach 2: O(log N) Time using Matrix Exponentiation
    int climbStairsMatrix(int n) {
        if (n <= 2) return n;

        // Multiply 2x2 matrices
        auto multiply = [](const std::vector<std::vector<long long>>& A, 
                           const std::vector<std::vector<long long>>& B) {
            std::vector<std::vector<long long>> C(2, std::vector<long long>(2, 0));
            C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
            C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
            C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
            C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
            return C;
        };

        // Binary matrix exponentiation
        std::vector<std::vector<long long>> result = {{1, 0}, {0, 1}};
        std::vector<std::vector<long long>> base = {{1, 1}, {1, 0}};

        int power = n - 1;
        while (power > 0) {
            if (power & 1) result = multiply(result, base);
            base = multiply(base, base);
            power >>= 1;
        }

        // result * [f(1), f(0)] where f(1) = 1, f(0) = 1
        return result[0][0] * 1 + result[0][1] * 1;
    }
};

int main() {
    Solution sol;

    std::cout << "climbStairs(2):  " << sol.climbStairs(2) << " (Expected: 2)\n";
    std::cout << "climbStairs(3):  " << sol.climbStairs(3) << " (Expected: 3)\n";
    std::cout << "climbStairs(5):  " << sol.climbStairs(5) << " (Expected: 8)\n";
    std::cout << "climbStairs(10): " << sol.climbStairs(10) << " (Expected: 89)\n";

    std::cout << "\nMatrix Exponentiation Test:\n";
    std::cout << "climbStairsMatrix(10): " << sol.climbStairsMatrix(10) << " (Expected: 89)\n";
    std::cout << "climbStairsMatrix(20): " << sol.climbStairsMatrix(20) << " (Expected: 10946)\n";

    return 0;
}

