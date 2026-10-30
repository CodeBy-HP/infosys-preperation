#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
private:
    bool canPlace(const std::vector<int>& position, int minDist, int m) {
        int count = 1;
        int lastPos = position[0];

        for (size_t i = 1; i < position.size(); ++i) {
            if (position[i] - lastPos >= minDist) {
                count++;
                lastPos = position[i];
                if (count >= m) return true;
            }
        }

        return false;
    }

public:
    int maxDistance(std::vector<int>& position, int m) {
        std::sort(position.begin(), position.end());

        int left = 1;
        int right = position.back() - position.front();
        int ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canPlace(position, mid, m)) {
                ans = mid;
                left = mid + 1; // Try larger minimum force
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<int> pos1 = {1, 2, 3, 4, 7};
    int m1 = 3;
    std::cout << "maxDistance([1,2,3,4,7], 3): " << sol.maxDistance(pos1, m1) 
              << " (Expected: 3)\n";

    std::vector<int> pos2 = {5, 4, 3, 2, 1, 1000000000};
    int m2 = 2;
    std::cout << "maxDistance([1..10^9], 2):    " << sol.maxDistance(pos2, m2) 
              << " (Expected: 999999999)\n";

    return 0;
}
