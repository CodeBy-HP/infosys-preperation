#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    long long maxSubarrayWithOneBitwiseNot(const vector<int>& arr) {
        int n = arr.size();
        // ~x in 32-bit signed two's complement is (-1LL * x - 1)
        auto bitNot = [](int x) -> long long {
            return static_cast<long long>(~x);
        };

        long long noFlip = arr[0];
        long long oneFlip = bitNot(arr[0]);
        long long ans = max(noFlip, oneFlip);

        for (int i = 1; i < n; i++) {
            long long flipped = bitNot(arr[i]);
            long long nextOneFlip = max({oneFlip + arr[i], noFlip + flipped, flipped});
            long long nextNoFlip = max(static_cast<long long>(arr[i]), noFlip + arr[i]);

            noFlip = nextNoFlip;
            oneFlip = nextOneFlip;
            ans = max({ans, noFlip, oneFlip});
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.maxSubarrayWithOneBitwiseNot({2, -10, 3}) == 14); // 2 + 9 + 3
    assert(sol.maxSubarrayWithOneBitwiseNot({-5, -1, -3}) == 4); // ~(-5) = 4
    assert(sol.maxSubarrayWithOneBitwiseNot({4, 5, 6}) == 15);   // 0 ops
    cout << "15_max_subarray_one_bitwise_not passed all tests!\n";
    return 0;
}
