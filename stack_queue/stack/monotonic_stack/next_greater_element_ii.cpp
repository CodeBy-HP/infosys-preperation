#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NextGreaterElementII {
public:
    // =========================================================================
    // 1. Monotonic Stack with Virtual Array Doubling
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> nextGreaterElements(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st; // Stores elements

        // Loop twice from right to left
        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = nums[i % n];

            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            if (i < n) {
                result[i] = st.empty() ? -1 : st.top();
            }

            st.push(curr);
        }

        return result;
    }
};

int main() {
    NextGreaterElementII solver;

    vector<int> nums1 = {1, 2, 1};
    vector<int> res1 = solver.nextGreaterElements(nums1);
    cout << "Test 1: [ ";
    for (int v : res1) cout << v << " ";
    cout << "]\n(Expected: [ 2 -1 2 ])\n";

    vector<int> nums2 = {1, 2, 3, 4, 3};
    vector<int> res2 = solver.nextGreaterElements(nums2);
    cout << "Test 2: [ ";
    for (int v : res2) cout << v << " ";
    cout << "]\n(Expected: [ 2 3 4 -1 4 ])\n";

    return 0;
}
