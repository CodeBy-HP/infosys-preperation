#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class LargestRectangleInHistogram {
public:
    // =========================================================================
    // 1. Monotonic Increasing Stack (Single Pass)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            // Append virtual bar of height 0 at the end to flush the stack
            int currentH = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > currentH) {
                int h = heights[st.top()];
                st.pop();

                // Width extends between left boundary (st.top()) and right boundary (i)
                int leftBound = st.empty() ? -1 : st.top();
                int width = i - leftBound - 1;

                maxArea = max(maxArea, h * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main() {
    LargestRectangleInHistogram solver;

    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Max Rectangle Area: " << solver.largestRectangleArea(heights) << " (Expected: 10)\n";

    return 0;
}
