#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class SlidingWindowMaximum {
public:
    // =========================================================================
    // 1. Monotonic Decreasing Deque
    // Time Complexity: O(N)
    // Space Complexity: O(K)
    // =========================================================================
    vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
        deque<int> dq; // Stores indices
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Remove indices that fell out of window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain decreasing monotonicity
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            // Record window maximum once first window of size k is complete
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    SlidingWindowMaximum solver;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = solver.maxSlidingWindow(nums, 3);

    cout << "Sliding Window Max: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ 3 3 5 5 6 7 ])\n";

    return 0;
}
