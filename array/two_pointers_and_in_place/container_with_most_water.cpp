#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ContainerWithMostWater {
public:
    // =========================================================================
    // 1. Two-Pointer Shrinking Bottleneck
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int maxArea(const vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int minH = min(height[left], height[right]);
            maxWater = max(maxWater, width * minH);

            // Discard the shorter boundary
            if (height[left] <= height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};

int main() {
    ContainerWithMostWater solver;

    vector<int> h = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Water: " << solver.maxArea(h) << " (Expected: 49)\n";

    return 0;
}
