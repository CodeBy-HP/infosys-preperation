#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long square = (long long)mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
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
    std::cout << "mySqrt(4):  " << sol.mySqrt(4) << " (Expected: 2)\n";
    std::cout << "mySqrt(8):  " << sol.mySqrt(8) << " (Expected: 2)\n";
    std::cout << "mySqrt(16): " << sol.mySqrt(16) << " (Expected: 4)\n";
    std::cout << "mySqrt(2147395599): " << sol.mySqrt(2147395599) << " (Expected: 46339)\n";

    return 0;
}
