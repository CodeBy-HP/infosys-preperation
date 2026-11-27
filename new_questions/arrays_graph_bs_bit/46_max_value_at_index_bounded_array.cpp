#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    long long calcSideSum(long long x, long long len) {
        // Peak at index has value x; adjacent elements start at x - 1 down to 1
        if (x > len) {
            // Triangle trapezoid: (x - 1) + (x - 2) + ... + (x - len)
            long long first = x - 1;
            long long last = x - len;
            return (first + last) * len / 2;
        } else {
            // Slopes down to 1 in (x - 1) steps, then remaining elements are 1s
            long long decLen = x - 1;
            long long triSum = x * decLen / 2;
            long long ones = len - decLen;
            return triSum + ones;
        }
    }

public:
    int maxValue(int n, int index, int maxSum) {
        long long left = 1, right = maxSum;
        int ans = 1;

        long long leftLen = index;
        long long rightLen = n - index - 1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long total = mid + calcSideSum(mid, leftLen) + calcSideSum(mid, rightLen);

            if (total <= maxSum) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.maxValue(4, 2, 6) == 2);
    assert(sol.maxValue(6, 1, 10) == 3);
    assert(sol.maxValue(1, 0, 1000000000) == 1000000000);
    cout << "46_max_value_at_index_bounded_array passed all tests!\n";
    return 0;
}
