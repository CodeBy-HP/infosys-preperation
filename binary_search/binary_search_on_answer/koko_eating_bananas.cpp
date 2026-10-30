#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    bool canFinish(const std::vector<int>& piles, int speed, int h) {
        long long hours = 0;
        for (int p : piles) {
            // Ceiling division: (p + speed - 1) / speed
            hours += (p + speed - 1) / speed;
            if (hours > h) return false;
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(const std::vector<int>& piles, int h) {
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h)) {
                ans = mid;
                right = mid - 1; // Try slower speed
            } else {
                left = mid + 1;  // Must eat faster
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> piles1 = {3, 6, 7, 11};
    std::cout << "minEatingSpeed([3,6,7,11], 8): " << sol.minEatingSpeed(piles1, 8) 
              << " (Expected: 4)\n";

    std::vector<int> piles2 = {30, 11, 23, 4, 20};
    std::cout << "minEatingSpeed([30,11,23,4,20], 5): " << sol.minEatingSpeed(piles2, 5) 
              << " (Expected: 30)\n";

    return 0;
}
