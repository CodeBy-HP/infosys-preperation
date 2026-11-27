#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Generalized Edit Distance with custom Insert, Delete, Replace costs in O(N) space
    int minCostTransform(const string& word1, const string& word2,
                         int insCost = 1, int delCost = 1, int repCost = 1) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, 0);

        for (int j = 0; j <= n; j++) {
            dp[j] = j * insCost;
        }

        for (int i = 1; i <= m; i++) {
            int prevDiag = dp[0];
            dp[0] = i * delCost;
            for (int j = 1; j <= n; j++) {
                int temp = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prevDiag;
                } else {
                    int delOp = dp[j] + delCost;
                    int insOp = dp[j - 1] + insCost;
                    int repOp = prevDiag + repCost;
                    dp[j] = min({delOp, insOp, repOp});
                }
                prevDiag = temp;
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    assert(sol.minCostTransform("horse", "ros") == 3);
    assert(sol.minCostTransform("intention", "execution") == 5);
    assert(sol.minCostTransform("abc", "adc", 5, 5, 2) == 2);
    cout << "16_min_cost_string_transformation passed all tests!\n";
    return 0;
}
