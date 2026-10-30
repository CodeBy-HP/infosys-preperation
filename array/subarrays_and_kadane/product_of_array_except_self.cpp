#include <iostream>
#include <vector>

using namespace std;

class ProductOfArrayExceptSelf {
public:
    // =========================================================================
    // 1. Two-Pass Prefix and Suffix Product
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary space (excluding result vector)
    // =========================================================================
    vector<int> productExceptSelf(const vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Pass 1: Prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Pass 2: Suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};

int main() {
    ProductOfArrayExceptSelf solver;

    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = solver.productExceptSelf(nums);

    cout << "Product Except Self: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ 24 12 8 6 ])\n";

    return 0;
}
