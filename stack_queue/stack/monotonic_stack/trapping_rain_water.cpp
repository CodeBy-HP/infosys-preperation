#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class TrappingRainWater {
public:
    // =========================================================================
    // 1. Two-Pointer Approach (O(1) Space)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int trapTwoPointers(const vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }

        return water;
    }

    // =========================================================================
    // 2. Monotonic Stack Approach (Horizontal Water Slices)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int trapStack(const vector<int>& height) {
        stack<int> st; // Stores indices
        int water = 0;

        for (int i = 0; i < (int)height.size(); i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int bottom = st.top();
                st.pop();

                if (st.empty()) break; // No left wall

                int left = st.top();
                int width = i - left - 1;
                int boundedHeight = min(height[left], height[i]) - height[bottom];

                water += width * boundedHeight;
            }
            st.push(i);
        }

        return water;
    }
};

int main() {
    TrappingRainWater solver;

    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water (Two Pointers): " << solver.trapTwoPointers(h) << " (Expected: 6)\n";
    cout << "Trapped Water (Stack):        " << solver.trapStack(h) << " (Expected: 6)\n";

    return 0;
}
