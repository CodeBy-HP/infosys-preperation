#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class BookAllocationProblem {
private:
    // Helper to calculate the number of students required if max pages per student is maxAllowed
    int countStudentsNeeded(const vector<int>& arr, long long maxAllowed) {
        int students = 1;
        long long currentPages = 0;

        for (int pages : arr) {
            if (currentPages + pages <= maxAllowed) {
                currentPages += pages;
            } else {
                students++;
                currentPages = pages;
            }
        }
        return students;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search on Answer
    // Time Complexity: O(N * log(sum(arr)))
    // Space Complexity: O(1)
    // =========================================================================
    long long findPagesOptimal(const vector<int>& arr, int n, int m) {
        // Impossible to allocate at least one book to each student
        if (m > n) return -1;

        long long left = *max_element(arr.begin(), arr.end());
        long long right = accumulate(arr.begin(), arr.end(), 0LL);
        long long ans = -1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            int students = countStudentsNeeded(arr, mid);

            if (students <= m) {
                ans = mid;        // Feasible, attempt a smaller max pages limit
                right = mid - 1;
            } else {
                left = mid + 1;   // Need more students than allowed, increase page limit
            }
        }
        return ans;
    }
};

int main() {
    BookAllocationProblem solver;

    vector<int> arr1 = {12, 34, 67, 90};
    int m1 = 2;
    cout << "Test 1: " << solver.findPagesOptimal(arr1, arr1.size(), m1) << " (Expected: 113)\n";

    vector<int> arr2 = {25, 46, 28, 49, 24};
    int m2 = 4;
    cout << "Test 2: " << solver.findPagesOptimal(arr2, arr2.size(), m2) << " (Expected: 71)\n";

    vector<int> arr3 = {10, 20, 30};
    int m3 = 4;
    cout << "Test 3: " << solver.findPagesOptimal(arr3, arr3.size(), m3) << " (Expected: -1)\n";

    return 0;
}

