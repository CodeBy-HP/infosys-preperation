#include <iostream>
#include <cmath>

using namespace std;

class NthRootOfNumber {
private:
    // Helper to evaluate mid^n compared to m:
    // Returns:
    //  1 if mid^n == m
    //  2 if mid^n > m
    //  0 if mid^n < m
    int checkPower(long long mid, int n, int m) {
        long long ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * mid;
            if (ans > m) return 2; // Exceeded m early to prevent overflow
        }
        if (ans == m) return 1;
        return 0;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search with Overflow Protection
    // Time Complexity: O(n * log m)
    // Space Complexity: O(1)
    // =========================================================================
    int nthRootOptimal(int n, int m) {
        if (m == 1 || n == 1) return m;

        int left = 1, right = m;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int status = checkPower(mid, n, m);

            if (status == 1) {
                return mid; // Exact root found
            } else if (status == 0) {
                left = mid + 1; // mid^n < m, need larger base
            } else {
                right = mid - 1; // mid^n > m, need smaller base
            }
        }
        return -1; // No integer root exists
    }

    // =========================================================================
    // 2. Linear Search with Power Check
    // Time Complexity: O(n * m^(1/n))
    // Space Complexity: O(1)
    // =========================================================================
    int nthRootLinear(int n, int m) {
        for (long long i = 1; i <= m; i++) {
            int status = checkPower(i, n, m);
            if (status == 1) return i;
            if (status == 2) break;
        }
        return -1;
    }

    // =========================================================================
    // 3. Mathematical Approximation with Rounding Verification
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    // =========================================================================
    int nthRootMath(int n, int m) {
        int root = round(pow(m, 1.0 / n));
        if (checkPower(root, n, m) == 1) return root;
        return -1;
    }
};

int main() {
    NthRootOfNumber solver;

    cout << "Test 1 (N=3, M=27): " << solver.nthRootOptimal(3, 27) << " (Expected: 3)\n";
    cout << "Test 2 (N=4, M=69): " << solver.nthRootOptimal(4, 69) << " (Expected: -1)\n";
    cout << "Test 3 (N=1, M=14): " << solver.nthRootOptimal(1, 14) << " (Expected: 14)\n";
    cout << "Test 4 (N=9, M=512): " << solver.nthRootOptimal(9, 512) << " (Expected: 2)\n";

    return 0;
}

