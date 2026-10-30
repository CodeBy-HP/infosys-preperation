#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class DailyTemperatures {
public:
    // =========================================================================
    // 1. Monotonic Decreasing Index Stack
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    vector<int> dailyTemperatures(const vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st; // Stores day indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                result[prevDay] = i - prevDay;
            }
            st.push(i);
        }

        return result;
    }
};

int main() {
    DailyTemperatures solver;

    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = solver.dailyTemperatures(temps);

    cout << "Wait Days: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ 1 1 4 2 1 1 0 0 ])\n";

    return 0;
}
