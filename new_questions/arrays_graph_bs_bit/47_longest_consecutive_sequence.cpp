#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // Only initiate streak count from sequence starts
            if (!numSet.count(num - 1)) {
                int curr = num;
                int streak = 1;
                while (numSet.count(curr + 1)) {
                    curr++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    assert(sol.longestConsecutive({100, 4, 200, 1, 3, 2}) == 4);
    assert(sol.longestConsecutive({0, 3, 7, 2, 5, 8, 4, 6, 0, 1}) == 9);
    assert(sol.longestConsecutive({}) == 0);
    cout << "47_longest_consecutive_sequence passed all tests!\n";
    return 0;
}
