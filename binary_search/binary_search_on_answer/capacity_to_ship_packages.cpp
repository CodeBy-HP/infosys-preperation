#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
private:
    bool canShip(const std::vector<int>& weights, int capacity, int days) {
        int daysUsed = 1;
        int currentWeight = 0;

        for (int w : weights) {
            if (currentWeight + w > capacity) {
                daysUsed++;
                currentWeight = 0;
            }
            currentWeight += w;
        }

        return daysUsed <= days;
    }

public:
    int shipWithinDays(const std::vector<int>& weights, int days) {
        int left = *std::max_element(weights.begin(), weights.end());
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canShip(weights, mid, days)) {
                ans = mid;
                right = mid - 1; // Try smaller capacity
            } else {
                left = mid + 1;  // Need bigger capacity
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int days = 5;

    std::cout << "shipWithinDays: " << sol.shipWithinDays(weights, days) 
              << " (Expected: 15)\n";

    return 0;
}
