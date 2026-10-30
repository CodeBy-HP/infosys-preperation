#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    bool canMake(const std::vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int consecutive = 0;

        for (int b : bloomDay) {
            if (b <= day) {
                consecutive++;
                if (consecutive == k) {
                    bouquets++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(const std::vector<int>& bloomDay, int m, int k) {
        long long required = (long long)m * k;
        if (required > (long long)bloomDay.size()) return -1;

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, mid, m, k)) {
                ans = mid;
                right = mid - 1; // Try fewer days
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> bloomDay = {1, 10, 3, 10, 2};
    std::cout << "minDays({1,10,3,10,2}, m=3, k=1): " << sol.minDays(bloomDay, 3, 1) 
              << " (Expected: 3)\n";
    std::cout << "minDays({1,10,3,10,2}, m=3, k=2): " << sol.minDays(bloomDay, 3, 2) 
              << " (Expected: -1)\n";

    return 0;
}
