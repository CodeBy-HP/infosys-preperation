#include <iostream>
#include <vector>
#include <deque>

class Solution {
public:
    std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::deque<int> dq; // Stores indices of elements, values are strictly decreasing

        for (int i = 0; i < (int)nums.size(); ++i) {
            // 1. Remove indices outside the current window [i - k + 1, i]
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Remove indices whose values are <= nums[i] (they can never be the max)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Push current index
            dq.push_back(i);

            // 4. Window is valid once we've processed at least k elements
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> res = sol.maxSlidingWindow(nums, k);
    std::cout << "Max Sliding Window (k=3): [ ";
    for (int x : res) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 3 3 5 5 6 7 ])\n";

    return 0;
}
