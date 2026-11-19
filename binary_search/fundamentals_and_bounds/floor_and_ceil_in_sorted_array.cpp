#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class FloorAndCeil {
public:
    // =========================================================================
    // 1. Optimal Binary Search (Dual-Pointers)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    int findFloor(const vector<int>& arr, int x) {
        int left = 0, right = arr.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] <= x) {
                ans = arr[mid];
                left = mid + 1; // Try to find a larger value <= x
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    int findCeil(const vector<int>& arr, int x) {
        int left = 0, right = arr.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= x) {
                ans = arr[mid];
                right = mid - 1; // Try to find a smaller value >= x
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    pair<int, int> getFloorAndCeil(const vector<int>& arr, int x) {
        return {findFloor(arr, x), findCeil(arr, x)};
    }

    // =========================================================================
    // 2. Standard Library Implementation (using lower_bound)
    // Time Complexity: O(log N)
    // Space Complexity: O(1)
    // =========================================================================
    pair<int, int> getFloorAndCeilSTL(const vector<int>& arr, int x) {
        auto it = lower_bound(arr.begin(), arr.end(), x);
        int ceilVal = (it != arr.end()) ? *it : -1;

        int floorVal = -1;
        if (it != arr.end() && *it == x) {
            floorVal = *it;
        } else if (it != arr.begin()) {
            floorVal = *(prev(it));
        }

        return {floorVal, ceilVal};
    }

    // =========================================================================
    // 3. Linear Scan (Brute Force baseline)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    pair<int, int> getFloorAndCeilLinear(const vector<int>& arr, int x) {
        int floorVal = -1, ceilVal = -1;
        for (int val : arr) {
            if (val <= x) floorVal = val;
            if (val >= x && ceilVal == -1) ceilVal = val;
        }
        return {floorVal, ceilVal};
    }
};

int main() {
    FloorAndCeil solver;

    vector<int> arr = {3, 4, 4, 7, 8, 10};

    auto res1 = solver.getFloorAndCeil(arr, 5);
    cout << "Floor and Ceil for 5: [" << res1.first << ", " << res1.second << "] (Expected: [4, 7])\n";

    auto res2 = solver.getFloorAndCeil(arr, 2);
    cout << "Floor and Ceil for 2: [" << res2.first << ", " << res2.second << "] (Expected: [-1, 3])\n";

    auto res3 = solver.getFloorAndCeil(arr, 11);
    cout << "Floor and Ceil for 11: [" << res3.first << ", " << res3.second << "] (Expected: [10, -1])\n";

    return 0;
}

