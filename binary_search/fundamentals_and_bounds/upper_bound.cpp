#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UpperBound {
public:
    // =========================================================================
    // 1. Optimal Binary Search (Iterative Implementation)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int upperBoundCustom(const vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = n; // Default if no element is strictly greater

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) {
                ans = mid;        // Valid candidate found
                right = mid - 1;  // Look for smaller index on the left
            } else {
                left = mid + 1;   // Must search on the right
            }
        }
        return ans;
    }

    // =========================================================================
    // 2. Standard Library Equivalent (std::upper_bound)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int upperBoundSTL(const vector<int>& arr, int target) {
        auto it = upper_bound(arr.begin(), arr.end(), target);
        return static_cast<int>(it - arr.begin());
    }

    // =========================================================================
    // 3. Linear Scan (Brute Force baseline)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int upperBoundLinear(const vector<int>& arr, int target) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] > target) {
                return i;
            }
        }
        return n;
    }
};

int main() {
    UpperBound solver;

    vector<int> arr1 = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    cout << "Test 1 Custom (target=6):  " << solver.upperBoundCustom(arr1, 6) << " (Expected: 3)\n";
    cout << "Test 1 STL    (target=6):  " << solver.upperBoundSTL(arr1, 6) << " (Expected: 3)\n";

    cout << "Test 2 Custom (target=11): " << solver.upperBoundCustom(arr1, 11) << " (Expected: 9)\n";

    vector<int> arr2 = {1, 2, 5, 6};
    cout << "Test 3 Custom (target=10): " << solver.upperBoundCustom(arr2, 10) << " (Expected: 4)\n";

    return 0;
}

