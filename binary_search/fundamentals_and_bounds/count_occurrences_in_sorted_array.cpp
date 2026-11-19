#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CountOccurrences {
private:
    int lowerBound(const vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        int ans = arr.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(const vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        int ans = arr.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search via Bound Subtraction
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int countOptimal(const vector<int>& arr, int target) {
        int lb = lowerBound(arr, target);
        // If target doesn't exist, lb will be out of range or not equal to target
        if (lb == static_cast<int>(arr.size()) || arr[lb] != target) {
            return 0;
        }
        int ub = upperBound(arr, target);
        return ub - lb;
    }

    // =========================================================================
    // 2. Standard Library Implementation (std::equal_range)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int countSTL(const vector<int>& arr, int target) {
        auto range = equal_range(arr.begin(), arr.end(), target);
        return static_cast<int>(distance(range.first, range.second));
    }

    // =========================================================================
    // 3. Linear Scan (Brute Force baseline)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int countLinear(const vector<int>& arr, int target) {
        int count = 0;
        for (int val : arr) {
            if (val == target) count++;
        }
        return count;
    }
};

int main() {
    CountOccurrences solver;

    vector<int> arr1 = {1, 1, 2, 2, 2, 2, 3};
    cout << "Test 1 Optimal (target=2): " << solver.countOptimal(arr1, 2) << " (Expected: 4)\n";
    cout << "Test 1 STL     (target=2): " << solver.countSTL(arr1, 2) << " (Expected: 4)\n";
    cout << "Test 1 Linear  (target=2): " << solver.countLinear(arr1, 2) << " (Expected: 4)\n";

    cout << "Test 2 Optimal (target=4): " << solver.countOptimal(arr1, 4) << " (Expected: 0)\n";

    vector<int> arr2 = {8, 9, 10, 12, 12, 12};
    cout << "Test 3 Optimal (target=12): " << solver.countOptimal(arr2, 12) << " (Expected: 3)\n";

    return 0;
}

