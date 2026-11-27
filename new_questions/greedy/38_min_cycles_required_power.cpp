#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Pair Sum Power (a + b)
    int minCyclesSumMode(vector<int> arr, long long T) {
        if (T <= 0) return 0;
        sort(arr.rbegin(), arr.rend());
        long long total = 0;
        int cycles = 0;

        for (size_t i = 0; i + 1 < arr.size(); i += 2) {
            total += static_cast<long long>(arr[i]) + arr[i + 1];
            cycles++;
            if (total >= T) return cycles;
        }
        return -1;
    }

    // Variant B: Pair Absolute Difference Power (|a - b|)
    int minCyclesDiffMode(vector<int> arr, long long T) {
        if (T <= 0) return 0;
        sort(arr.begin(), arr.end());
        long long total = 0;
        int cycles = 0;
        int l = 0, r = static_cast<int>(arr.size()) - 1;

        while (l < r) {
            total += static_cast<long long>(arr[r]) - arr[l];
            cycles++;
            if (total >= T) return cycles;
            l++;
            r--;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    assert(sol.minCyclesSumMode({3, 8, 2, 5, 10}, 20) == 2);
    assert(sol.minCyclesSumMode({1, 2, 3}, 10) == -1);
    assert(sol.minCyclesDiffMode({1, 10, 2, 9}, 15) == 2); // |10-1| + |9-2| = 16
    cout << "38_min_cycles_required_power passed all tests!\n";
    return 0;
}
