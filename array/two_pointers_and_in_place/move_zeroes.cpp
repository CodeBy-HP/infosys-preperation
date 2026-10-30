#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class MoveZeroes {
public:
    // =========================================================================
    // 1. Two-Pointer In-Place Swap
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    void moveZeroes(vector<int>& nums) {
        int writer = 0;

        for (int reader = 0; reader < (int)nums.size(); reader++) {
            if (nums[reader] != 0) {
                swap(nums[writer], nums[reader]);
                writer++;
            }
        }
    }
};

int main() {
    MoveZeroes solver;

    vector<int> nums = {0, 1, 0, 3, 12};
    solver.moveZeroes(nums);

    cout << "Moved Zeroes: [ ";
    for (int v : nums) cout << v << " ";
    cout << "]\n(Expected: [ 1 3 12 0 0 ])\n";

    return 0;
}
