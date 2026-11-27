#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Individual +1 increments only
    long long minOpsIndividualIncrement(const vector<int>& temps) {
        if (temps.empty()) return 0;
        int maxTemp = *max_element(temps.begin(), temps.end());
        long long ops = 0;
        for (int t : temps) {
            ops += static_cast<long long>(maxTemp) - t;
        }
        return ops;
    }

    // Variant B: Contiguous Subarray +1 increments to reach max(temps)
    long long minOpsRangeIncrement(const vector<int>& temps) {
        if (temps.empty()) return 0;
        int maxTemp = *max_element(temps.begin(), temps.end());

        long long prevDeficit = maxTemp - temps[0];
        long long ops = prevDeficit;

        for (size_t i = 1; i < temps.size(); i++) {
            long long currDeficit = maxTemp - temps[i];
            if (currDeficit > prevDeficit) {
                ops += currDeficit - prevDeficit;
            }
            prevDeficit = currDeficit;
        }
        return ops;
    }
};

int main() {
    Solution sol;
    assert(sol.minOpsIndividualIncrement({3, 2, 5, 2, 3}) == 10);
    assert(sol.minOpsRangeIncrement({1, 3, 2}) == 3);
    assert(sol.minOpsRangeIncrement({5, 2, 2, 5}) == 3); // deficits: [0, 3, 3, 0] -> 3 range ops
    cout << "42_equalize_temperature_regulators passed all tests!\n";
    return 0;
}
