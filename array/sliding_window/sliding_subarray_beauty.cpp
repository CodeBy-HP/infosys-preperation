#include <iostream>
#include <vector>

using namespace std;

class SlidingSubarrayBeauty {
public:
    // =========================================================================
    // 1. Sliding Window with Value-Bounded Frequency Buckets (-50 to -1)
    // Time Complexity: O(N * 50) = O(N)
    // Space Complexity: O(51) = O(1)
    // =========================================================================
    vector<int> getSubarrayBeauty(const vector<int>& nums, int k, int x) {
        // count[i] stores frequency of negative number -i (index 1 to 50)
        vector<int> count(51, 0);
        vector<int> result;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                count[abs(nums[i])]++;
            }

            // Remove outgoing element from left of window
            if (i >= k && nums[i - k] < 0) {
                count[abs(nums[i - k])]--;
            }

            // Query when window of size k is formed
            if (i >= k - 1) {
                int runningCount = 0;
                int beauty = 0;

                // Scan buckets from smallest (-50) to largest negative (-1)
                for (int val = 50; val >= 1; val--) {
                    runningCount += count[val];
                    if (runningCount >= x) {
                        beauty = -val;
                        break;
                    }
                }
                result.push_back(beauty);
            }
        }

        return result;
    }
};

int main() {
    SlidingSubarrayBeauty solver;

    vector<int> nums = {1, -1, -3, -2, 3};
    vector<int> res = solver.getSubarrayBeauty(nums, 3, 2);

    cout << "Subarray Beauty: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ -1 -2 -2 ])\n";

    return 0;
}
