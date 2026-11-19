#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class RemoveKDigits {
public:
    // =========================================================================
    // 1. Optimal Monotonic Stack using std::string as stack
    // Time Complexity: O(N) where N = num.length()
    // Space Complexity: O(N) to store result buffer
    // =========================================================================
    string removeKdigitsOptimal(string num, int k) {
        if (k >= static_cast<int>(num.size())) return "0";

        string st = "";
        for (char c : num) {
            // While previous digit is larger and we still have quotas to remove
            while (!st.empty() && k > 0 && st.back() > c) {
                st.pop_back();
                k--;
            }
            st.push_back(c);
        }

        // If k > 0, truncate from the end (monotonic increasing tail)
        while (k > 0 && !st.empty()) {
            st.pop_back();
            k--;
        }

        // Remove leading zeroes
        int nonZeroIdx = 0;
        while (nonZeroIdx < static_cast<int>(st.size()) && st[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }

        string result = st.substr(nonZeroIdx);
        return result.empty() ? "0" : result;
    }

    // =========================================================================
    // 2. Monotonic Stack using std::stack<char>
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    string removeKdigitsStack(string num, int k) {
        if (k >= static_cast<int>(num.size())) return "0";

        stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string res = "";
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        int start = 0;
        while (start < static_cast<int>(res.size()) && res[start] == '0') {
            start++;
        }
        res = res.substr(start);
        return res.empty() ? "0" : res;
    }

    // =========================================================================
    // 3. Greedy Iterative Simulation (Find first peak)
    // Time Complexity: O(k * N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    string removeKdigitsGreedy(string num, int k) {
        if (k >= static_cast<int>(num.size())) return "0";

        while (k > 0) {
            int i = 0;
            while (i + 1 < static_cast<int>(num.size()) && num[i] <= num[i + 1]) {
                i++;
            }
            num.erase(num.begin() + i);
            k--;
        }

        int start = 0;
        while (start < static_cast<int>(num.size()) && num[start] == '0') {
            start++;
        }
        num = num.substr(start);
        return num.empty() ? "0" : num;
    }
};

int main() {
    RemoveKDigits solver;

    string num1 = "1432219";
    int k1 = 3;
    cout << "Test 1 Optimal: " << solver.removeKdigitsOptimal(num1, k1) << " (Expected: 1219)\n";
    cout << "Test 1 Stack:   " << solver.removeKdigitsStack(num1, k1) << " (Expected: 1219)\n";
    cout << "Test 1 Greedy:  " << solver.removeKdigitsGreedy(num1, k1) << " (Expected: 1219)\n";

    string num2 = "10200";
    int k2 = 1;
    cout << "Test 2 Optimal: " << solver.removeKdigitsOptimal(num2, k2) << " (Expected: 200)\n";

    string num3 = "10";
    int k3 = 2;
    cout << "Test 3 Optimal: " << solver.removeKdigitsOptimal(num3, k3) << " (Expected: 0)\n";

    string num4 = "9";
    int k4 = 1;
    cout << "Test 4 Optimal: " << solver.removeKdigitsOptimal(num4, k4) << " (Expected: 0)\n";

    return 0;
}

