#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class FindRotationCount {
public:
    // =========================================================================
    // 1. Optimal Binary Search (Pivot Index Detection)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int findKRotationOptimal(const vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int minVal = INT_MAX;
        int minIndex = 0;

        while (left <= right) {
            // Case 1: Entire current search space is already sorted
            if (arr[left] <= arr[right]) {
                if (arr[left] < minVal) {
                    minVal = arr[left];
                    minIndex = left;
                }
                break;
            }

            int mid = left + (right - left) / 2;

            // Case 2: Left half is sorted
            if (arr[left] <= arr[mid]) {
                if (arr[left] < minVal) {
                    minVal = arr[left];
                    minIndex = left;
                }
                left = mid + 1; // Pivot must be in the right half
            } else {
                // Case 3: Right half is sorted
                if (arr[mid] < minVal) {
                    minVal = arr[mid];
                    minIndex = mid;
                }
                right = mid - 1; // Pivot must be in the left half
            }
        }
        return minIndex;
    }

    // =========================================================================
    // 2. Binary Search comparing mid against right
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int findKRotationRightCompare(const vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    // =========================================================================
    // 3. Linear Scan (Brute Force baseline)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int findKRotationLinear(const vector<int>& arr) {
        int minIndex = 0;
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] < arr[minIndex]) {
                minIndex = i;
            }
        }
        return minIndex;
    }
};

int main() {
    FindRotationCount solver;

    vector<int> arr1 = {4, 5, 6, 7, 0, 1, 2};
    cout << "Test 1 Optimal:      " << solver.findKRotationOptimal(arr1) << " (Expected: 4)\n";
    cout << "Test 1 RightCompare: " << solver.findKRotationRightCompare(arr1) << " (Expected: 4)\n";

    vector<int> arr2 = {3, 4, 5, 1, 2};
    cout << "Test 2 Optimal:      " << solver.findKRotationOptimal(arr2) << " (Expected: 3)\n";

    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout << "Test 3 Optimal:      " << solver.findKRotationOptimal(arr3) << " (Expected: 0)\n";

    return 0;
}

