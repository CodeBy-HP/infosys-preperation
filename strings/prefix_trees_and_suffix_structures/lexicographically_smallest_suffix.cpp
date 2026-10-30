#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LexicographicallySmallestSuffix {
private:
    const int MOD = 1e9 + 7;

public:
    // =========================================================================
    // 1. Suffix Array Binary Search
    // Time Complexity: O(N log^2 N + Q * |T| log N)
    // Space Complexity: O(N)
    // =========================================================================
    long long processQueries(const string& s, const vector<string>& queries) {
        int n = s.size();

        // Build suffix array: store starting indices of all suffixes
        vector<int> sa(n);
        for (int i = 0; i < n; i++) sa[i] = i;

        sort(sa.begin(), sa.end(), [&](int a, int b) {
            return s.compare(a, string::npos, s, b, string::npos) < 0;
        });

        long long totalSum = 0;

        for (const string& t : queries) {
            int m = t.size();
            // Binary search for smallest suffix starting with t
            int low = 0, high = n - 1;
            int bestIdx = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                int suffixStart = sa[mid];

                // Compare prefix of length m
                int cmp = s.compare(suffixStart, m, t);
                if (cmp >= 0) {
                    if (cmp == 0) bestIdx = mid;
                    high = mid - 1; // Seek earlier (smaller) matches
                } else {
                    low = mid + 1;
                }
            }

            if (bestIdx != -1) {
                int suffixLen = n - sa[bestIdx];
                totalSum = (totalSum + suffixLen) % MOD;
            }
        }

        return totalSum;
    }
};

int main() {
    LexicographicallySmallestSuffix solver;

    string s = "mzadpoghyykht";
    vector<string> queries = {"yk"};

    cout << "Total Query Sum: " << solver.processQueries(s, queries) << " (Expected: 4)\n";

    return 0;
}
