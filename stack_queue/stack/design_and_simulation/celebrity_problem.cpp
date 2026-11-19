#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class CelebrityProblem {
private:
    // Helper function to query knowledge relation
    bool knows(const vector<vector<int>>& M, int a, int b) {
        return M[a][b] == 1;
    }

public:
    // =========================================================================
    // 1. Stack-Based Elimination
    // Time Complexity: O(N)
    // Space Complexity: O(N) for the elimination stack
    // =========================================================================
    int findCelebrityStack(const vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return -1;

        stack<int> st;
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Eliminate one candidate per comparison
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            if (knows(M, a, b)) {
                // 'a' knows 'b' -> 'a' cannot be celebrity
                st.push(b);
            } else {
                // 'a' does not know 'b' -> 'b' cannot be celebrity
                st.push(a);
            }
        }

        if (st.empty()) return -1;
        int cand = st.top();

        // Verification step: candidate must know 0 people, and all N-1 others must know candidate
        for (int i = 0; i < n; i++) {
            if (i == cand) continue;
            // Candidate knows someone, or someone does not know candidate
            if (knows(M, cand, i) || !knows(M, i, cand)) {
                return -1;
            }
        }

        return cand;
    }

    // =========================================================================
    // 2. Optimal Two-Pointer Elimination
    // Time Complexity: O(N)
    // Space Complexity: O(1) auxiliary
    // =========================================================================
    int findCelebrityTwoPointers(const vector<vector<int>>& M) {
        int n = M.size();
        if (n == 0) return -1;

        int i = 0, j = n - 1;
        while (i < j) {
            if (knows(M, i, j)) {
                i++; // i knows j, i is not celebrity
            } else {
                j--; // i does not know j, j is not celebrity
            }
        }

        int cand = i;

        // Verification pass
        for (int k = 0; k < n; k++) {
            if (k == cand) continue;
            if (knows(M, cand, k) || !knows(M, k, cand)) {
                return -1;
            }
        }

        return cand;
    }

    // =========================================================================
    // 3. In-degree and Out-degree Counting
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    // =========================================================================
    int findCelebrityDegreeCount(const vector<vector<int>>& M) {
        int n = M.size();
        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && M[i][j] == 1) {
                    outdegree[i]++;
                    indegree[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    CelebrityProblem solver;

    vector<vector<int>> M1 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}
    };
    cout << "Test 1 Stack:        " << solver.findCelebrityStack(M1) << " (Expected: 1)\n";
    cout << "Test 1 Two Pointers: " << solver.findCelebrityTwoPointers(M1) << " (Expected: 1)\n";
    cout << "Test 1 Degree Count: " << solver.findCelebrityDegreeCount(M1) << " (Expected: 1)\n\n";

    vector<vector<int>> M2 = {
        {0, 1},
        {1, 0}
    };
    cout << "Test 2 Stack:        " << solver.findCelebrityStack(M2) << " (Expected: -1)\n";
    cout << "Test 2 Two Pointers: " << solver.findCelebrityTwoPointers(M2) << " (Expected: -1)\n";

    return 0;
}

