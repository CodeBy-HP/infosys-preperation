#include <iostream>
#include <vector>
#include <map>

using namespace std;

class DivisibleSumDiffPairs {
public:
    // =========================================================================
    // 1. Dual Modulo Pair Hash Map
    // Time Complexity: O(N log N) with map or O(N) with custom hash
    // Space Complexity: O(N)
    // =========================================================================
    long long countPairs(const vector<int>& a, int D, int M) {
        map<pair<int, int>, int> freq;
        long long validPairs = 0;

        for (int x : a) {
            int remD = x % D;
            int remM = x % M;

            int targetRemD = (D - remD) % D;
            int targetRemM = remM;

            // Check if complement exists
            auto it = freq.find({targetRemD, targetRemM});
            if (it != freq.end()) {
                validPairs += it->second;
            }

            freq[{remD, remM}]++;
        }

        return validPairs;
    }
};

int main() {
    DivisibleSumDiffPairs solver;

    vector<int> a = {2, 4, 6, 8};
    cout << "Valid Pairs: " << solver.countPairs(a, 2, 2) << " (Expected: 6)\n";

    return 0;
}
