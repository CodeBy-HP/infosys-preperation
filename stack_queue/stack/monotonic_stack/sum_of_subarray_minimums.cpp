#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SumOfSubarrayMinimums {
private:
    static const int MOD = 1e9 + 7;

public:
    // =========================================================================
    // 1. Two-Pass Monotonic Stack (PSE and NSE Arrays)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int sumSubarrayMinsOptimal(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, n);
        stack<int> st;

        // Find Previous Smaller Element (strict: <)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) pse[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Find Next Smaller or Equal Element (non-strict: <= to break ties)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) nse[i] = st.top();
            st.push(i);
        }

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long ways = (left * right) % MOD;
            total = (total + ways * arr[i]) % MOD;
        }

        return total;
    }

    // =========================================================================
    // 2. Single-Pass Monotonic Stack Approach
    // Computes contribution on the fly when element is popped from stack.
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int sumSubarrayMinsSinglePass(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long total = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int mid = st.top();
                st.pop();
                long long left = mid - (st.empty() ? -1 : st.top());
                long long right = i - mid;
                long long ways = (left * right) % MOD;
                total = (total + ways * arr[mid]) % MOD;
            }
            st.push(i);
        }

        return total;
    }
};

int main() {
    SumOfSubarrayMinimums solver;

    vector<int> arr1 = {3, 1, 2, 4};
    cout << "Test 1 [3, 1, 2, 4]:\n";
    cout << "  Optimal Two-Pass:   " << solver.sumSubarrayMinsOptimal(arr1) << "\n";
    cout << "  Single-Pass:        " << solver.sumSubarrayMinsSinglePass(arr1) << " (Expected: 17)\n";

    vector<int> arr2 = {11, 81, 94, 43, 3};
    cout << "\nTest 2 [11, 81, 94, 43, 3]:\n";
    cout << "  Optimal Two-Pass:   " << solver.sumSubarrayMinsOptimal(arr2) << " (Expected: 444)\n";

    return 0;
}

