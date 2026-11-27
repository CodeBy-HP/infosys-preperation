#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

class Solution {
public:
    int minOperations(const vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;

        int ops = 0;
        for (const auto& kv : freq) {
            int c = kv.second;
            if (c == 1) return -1;
            ops += (c + 2) / 3;
        }
        return ops;
    }
};

int main() {
    Solution sol;
    assert(sol.minOperations({2, 3, 3, 2, 2, 4, 2, 3, 4}) == 4);
    assert(sol.minOperations({2, 1, 2, 2, 3, 3}) == -1);
    cout << "43_min_operations_make_array_empty passed all tests!\n";
    return 0;
}
