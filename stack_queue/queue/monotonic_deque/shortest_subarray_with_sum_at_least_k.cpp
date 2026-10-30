#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int shortestSubarray(const std::vector<int>& nums, int k) {
        int n = nums.size();
        // Use long long for prefix sums to avoid 32-bit integer overflow
        std::vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        std::deque<int> dq;
        int minLen = n + 1;

        for (int j = 0; j <= n; ++j) {
            // Check if front satisfies prefix[j] - prefix[dq.front()] >= k
            while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
                minLen = std::min(minLen, j - dq.front());
                dq.pop_front(); // No need to check dq.front() again for future j
            }

            // Maintain monotonic increasing order of prefix sums
            while (!dq.empty() && prefix[j] <= prefix[dq.back()]) {
                dq.pop_back(); // dq.back() is dominated by j
            }

            dq.push_back(j);
        }

        return minLen <= n ? minLen : -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, -1, 2};
    int k1 = 3;
    std::cout << "Test 1 [2, -1, 2], k=3: " << sol.shortestSubarray(nums1, k1) 
              << " (Expected: 3)\n";

    std::vector<int> nums2 = {84, -37, 32, 40, 95};
    int k2 = 167;
    std::cout << "Test 2: " << sol.shortestSubarray(nums2, k2) 
              << " (Expected: 3)\n";

    return 0;
}
