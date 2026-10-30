#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class SortColors {
public:
    // =========================================================================
    // 1. Dutch National Flag 3-Way Partitioning
    // Time Complexity: O(N) single pass
    // Space Complexity: O(1) in-place
    // =========================================================================
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = (int)nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
                // Note: mid is NOT incremented because nums[high] needs evaluation
            }
        }
    }
};

int main() {
    SortColors solver;

    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solver.sortColors(nums);

    cout << "Sorted Colors: [ ";
    for (int v : nums) cout << v << " ";
    cout << "]\n(Expected: [ 0 0 1 1 2 2 ])\n";

    return 0;
}
