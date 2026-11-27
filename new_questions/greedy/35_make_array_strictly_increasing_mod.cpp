#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    long long minOperationsStrictlyIncreasingMod(const vector<int>& arr) {
        long long ops = 0;
        long long prev = LLONG_MIN;

        for (size_t i = 0; i < arr.size(); i++) {
            long long d = static_cast<long long>(i) + 1;
            long long L = max(static_cast<long long>(arr[i]), prev + 1);

            // Smallest multiple of d >= L (works for both positive and negative L)
            long long target;
            if (L >= 0) {
                target = ((L + d - 1) / d) * d;
            } else {
                target = (L / d) * d;
            }

            ops += (target - arr[i]);
            prev = target;
        }
        return ops;
    }
};

int main() {
    Solution sol;
    assert(sol.minOperationsStrictlyIncreasingMod({1, 3, 2}) == 5); // -> [1, 4, 6]
    assert(sol.minOperationsStrictlyIncreasingMod({2, 4, 6}) == 0);
    assert(sol.minOperationsStrictlyIncreasingMod({1, 1, 1}) == 3); // -> [1, 2, 3], ops = 0+1+2 = 3
    cout << "35_make_array_strictly_increasing_mod passed all tests!\n";
    return 0;
}
