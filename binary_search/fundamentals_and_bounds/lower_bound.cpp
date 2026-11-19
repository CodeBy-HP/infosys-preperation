#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class LowerBound {
public:
    // =========================================================================
    // 1. Optimal Binary Search (Iterative Implementation)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int lowerBoundCustom(const vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int ans = n; // Default if target is greater than all elements

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                ans = mid;        // Potential candidate found
                right = mid - 1;  // Look for smaller index on the left
            } else {
                left = mid + 1;   // Must search on the right
            }
        }
        return ans;
    }

    // =========================================================================
    // 2. Standard Library Equivalent (std::lower_bound)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int lowerBoundSTL(const vector<int>& arr, int target) {
        auto it = lower_bound(arr.begin(), arr.end(), target);
        return static_cast<int>(it - arr.begin());
    }

    // =========================================================================
    // 3. Linear Scan (Brute Force baseline)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int lowerBoundLinear(const vector<int>& arr, int target) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] >= target) {
                return i;
            }
        }
        return n;
    }
};

int main() {
    LowerBound solver;

    vector<int> arr1 = {1, 2, 8, 10, 11, 12, 19};
    cout << "Test 1 Custom (target=5): " << solver.lowerBoundCustom(arr1, 5) << " (Expected: 2)\n";
    cout << "Test 1 STL    (target=5): " << solver.lowerBoundSTL(arr1, 5) << " (Expected: 2)\n";

    vector<int> arr2 = {3, 5, 8, 15, 19};
    cout << "Test 2 Custom (target=9): " << solver.lowerBoundCustom(arr2, 9) << " (Expected: 3)\n";

    vector<int> arr3 = {2, 3, 7, 10, 11};
    cout << "Test 3 Custom (target=12): " << solver.lowerBoundCustom(arr3, 12) << " (Expected: 5)\n";

    return 0;
}

