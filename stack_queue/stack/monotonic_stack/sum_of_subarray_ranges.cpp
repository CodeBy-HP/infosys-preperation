#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class SumOfSubarrayRanges {
public:
    // =========================================================================
    // 1. Optimal O(N) Monotonic Stack Approach
    // Sum of Ranges = Sum(Subarray Maximums) - Sum(Subarray Minimums)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    long long subArrayRangesOptimal(const vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }

private:
    long long sumSubarrayMins(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long total = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] >= nums[i])) {
                int mid = st.top();
                st.pop();
                long long left = mid - (st.empty() ? -1 : st.top());
                long long right = i - mid;
                total += left * right * (long long)nums[mid];
            }
            st.push(i);
        }

        return total;
    }

    long long sumSubarrayMaxs(const vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long total = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || nums[st.top()] <= nums[i])) {
                int mid = st.top();
                st.pop();
                long long left = mid - (st.empty() ? -1 : st.top());
                long long right = i - mid;
                total += left * right * (long long)nums[mid];
            }
            st.push(i);
        }

        return total;
    }

public:
    // =========================================================================
    // 2. Brute Force O(N^2) Approach
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)
    // =========================================================================
    long long subArrayRangesBruteForce(const vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        for (int i = 0; i < n; i++) {
            int curMin = nums[i];
            int curMax = nums[i];
            for (int j = i + 1; j < n; j++) {
                curMin = min(curMin, nums[j]);
                curMax = max(curMax, nums[j]);
                total += (curMax - curMin);
            }
        }

        return total;
    }
};

int main() {
    SumOfSubarrayRanges solver;

    vector<int> nums1 = {1, 2, 3};
    cout << "Test 1 [1, 2, 3]:\n";
    cout << "  Optimal O(N):     " << solver.subArrayRangesOptimal(nums1) << "\n";
    cout << "  Brute Force O(N2): " << solver.subArrayRangesBruteForce(nums1) << " (Expected: 4)\n";

    vector<int> nums2 = {4, -2, -3, 4, 1};
    cout << "\nTest 2 [4, -2, -3, 4, 1]:\n";
    cout << "  Optimal O(N):     " << solver.subArrayRangesOptimal(nums2) << " (Expected: 59)\n";

    return 0;
}

