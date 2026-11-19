#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class NextSmallerElement {
public:
    // =========================================================================
    // 1. Next Smaller Element (To the Right)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> nextSmallerElement(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st; // Stores elements

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(arr[i]);
        }

        return nse;
    }

    // =========================================================================
    // 2. Previous Smaller Element (To the Left)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> prevSmallerElement(const vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(arr[i]);
        }

        return pse;
    }

    // =========================================================================
    // 3. Next Smaller Indices (Returns index instead of value; n if none)
    // =========================================================================
    vector<int> nextSmallerIndices(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nseIdx(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nseIdx[i] = st.top();
            }
            st.push(i);
        }

        return nseIdx;
    }
};

int main() {
    NextSmallerElement solver;

    vector<int> arr = {4, 5, 2, 10, 8};
    cout << "Array: [4, 5, 2, 10, 8]\n";

    vector<int> nse = solver.nextSmallerElement(arr);
    cout << "Next Smaller Element:     [";
    for (size_t i = 0; i < nse.size(); i++) cout << nse[i] << (i + 1 < nse.size() ? ", " : "]\n");

    vector<int> pse = solver.prevSmallerElement(arr);
    cout << "Previous Smaller Element: [";
    for (size_t i = 0; i < pse.size(); i++) cout << pse[i] << (i + 1 < pse.size() ? ", " : "]\n");

    return 0;
}

