#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class NextGreaterElementI {
public:
    // =========================================================================
    // 1. Monotonic Decreasing Stack with Hash Map Lookup
    // Time Complexity: O(N + M) where N = nums1.size(), M = nums2.size()
    // Space Complexity: O(M)
    // =========================================================================
    vector<int> nextGreaterElement(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int num : nums2) {
            // Resolve all smaller elements waiting in the stack
            while (!st.empty() && st.top() < num) {
                nextGreater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        vector<int> result;
        result.reserve(nums1.size());
        for (int q : nums1) {
            result.push_back(nextGreater.count(q) ? nextGreater[q] : -1);
        }

        return result;
    }
};

int main() {
    NextGreaterElementI solver;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = solver.nextGreaterElement(nums1, nums2);
    cout << "Next Greater Elements: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ -1 3 -1 ])\n";

    return 0;
}
