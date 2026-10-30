#include <iostream>
#include <vector>

using namespace std;

class MajorityElementII {
public:
    // =========================================================================
    // 1. Extended Boyer-Moore Voting (At most 2 candidates)
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary space
    // =========================================================================
    vector<int> majorityElement(const vector<int>& nums) {
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;

        // Pass 1: Find two candidate survivors
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Pass 2: Verify candidates exceed n / 3 threshold
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }

        vector<int> result;
        int n = nums.size();
        if (count1 > n / 3) result.push_back(cand1);
        if (count2 > n / 3) result.push_back(cand2);

        return result;
    }
};

int main() {
    MajorityElementII solver;

    vector<int> nums = {1, 2};
    vector<int> res = solver.majorityElement(nums);

    cout << "Majority Elements (> n/3): [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ 1 2 ])\n";

    return 0;
}
