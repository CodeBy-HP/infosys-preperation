#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxConsecutiveOnes {
public:
    // =========================================================================
    // 1. Single-Pass Running Counter
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int maxOnes = 0;
        int currentOnes = 0;

        for (int num : nums) {
            if (num == 1) {
                currentOnes++;
                maxOnes = max(maxOnes, currentOnes);
            } else {
                currentOnes = 0;
            }
        }

        return maxOnes;
    }
};

int main() {
    MaxConsecutiveOnes solver;

    vector<int> nums1 = {1, 1, 0, 1, 1, 1};
    cout << "Max Consecutive Ones: " << solver.findMaxConsecutiveOnes(nums1) << " (Expected: 3)\n";

    return 0;
}
