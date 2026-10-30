#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class TwoCitySchedulingTransit {
public:
    // =========================================================================
    // 1. Greedy Sorting by Opportunity Cost Difference
    // diff[i] = cost_B[i] - A[i]
    // Time Complexity: O(N log N)
    // Space Complexity: O(N)
    // =========================================================================
    long long twoCitySchedulingSorting(int n, const vector<int>& A, const vector<int>& B) {
        int totalEmployees = 2 * n;
        long long total = 0;

        vector<long long> diff(totalEmployees);

        for (int i = 0; i < totalEmployees; i++) {
            total += A[i];
            long long costB = min(A[i], B[i]) + B[i];
            diff[i] = costB - A[i];
        }

        sort(diff.begin(), diff.end());

        // Greedily divert the N employees with smallest opportunity cost to City B
        for (int i = 0; i < n; i++) {
            total += diff[i];
        }

        return total;
    }

    // =========================================================================
    // 2. Linear Time Approach using Quickselect (std::nth_element)
    // Time Complexity: O(N) average
    // Space Complexity: O(N)
    // =========================================================================
    long long twoCitySchedulingQuickSelect(int n, const vector<int>& A, const vector<int>& B) {
        int totalEmployees = 2 * n;
        long long total = 0;

        vector<long long> diff(totalEmployees);

        for (int i = 0; i < totalEmployees; i++) {
            total += A[i];
            long long costB = min(A[i], B[i]) + B[i];
            diff[i] = costB - A[i];
        }

        // Partition such that the smallest n elements are in the first n slots
        nth_element(diff.begin(), diff.begin() + n, diff.end());

        for (int i = 0; i < n; i++) {
            total += diff[i];
        }

        return total;
    }
};

int main() {
    TwoCitySchedulingTransit solver;

    int n = 2;
    vector<int> A = {10, 20, 30, 40};
    vector<int> B = {30, 20, 10, 20};

    cout << "Test 1 (N = 2, 4 employees):\n";
    cout << "  Sorting:     " << solver.twoCitySchedulingSorting(n, A, B) << "\n";
    cout << "  Quickselect: " << solver.twoCitySchedulingQuickSelect(n, A, B) << " (Expected: 90)\n";

    return 0;
}

