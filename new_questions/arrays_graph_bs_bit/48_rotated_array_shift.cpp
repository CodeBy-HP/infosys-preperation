#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    void rotateRight(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;
        if (k == 0) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    void rotateLeft(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;
        k %= n;
        if (k == 0) return;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    sol.rotateRight(a1, 3);
    assert((a1 == vector<int>{5, 6, 7, 1, 2, 3, 4}));

    vector<int> a2 = {1, 2, 3, 4, 5};
    sol.rotateLeft(a2, 2);
    assert((a2 == vector<int>{3, 4, 5, 1, 2}));
    cout << "48_rotated_array_shift passed all tests!\n";
    return 0;
}
