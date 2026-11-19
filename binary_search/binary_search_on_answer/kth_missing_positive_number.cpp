#include <iostream>
#include <vector>

using namespace std;

class KthMissingPositiveNumber {
public:
    // =========================================================================
    // 1. Optimal Binary Search on Missing Count
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int findKthPositiveOptimal(const vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int missingCount = arr[mid] - (mid + 1);

            if (missingCount < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // At termination, left == right + 1, and the missing number is left + k
        return left + k;
    }

    // =========================================================================
    // 2. Linear Scan with k-Decrement
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int findKthPositiveLinear(const vector<int>& arr, int k) {
        for (int num : arr) {
            if (num <= k) {
                k++; // Each element <= k shifts the target missing value by 1
            } else {
                break;
            }
        }
        return k;
    }
};

int main() {
    KthMissingPositiveNumber solver;

    vector<int> arr1 = {2, 3, 4, 7, 11};
    int k1 = 5;
    cout << "Test 1 Optimal: " << solver.findKthPositiveOptimal(arr1, k1) << " (Expected: 9)\n";
    cout << "Test 1 Linear:  " << solver.findKthPositiveLinear(arr1, k1) << " (Expected: 9)\n";

    vector<int> arr2 = {1, 2, 3, 4};
    int k2 = 2;
    cout << "Test 2 Optimal: " << solver.findKthPositiveOptimal(arr2, k2) << " (Expected: 6)\n";

    return 0;
}

