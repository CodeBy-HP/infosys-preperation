#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: LeetCode 1186 - Maximum Subarray Sum with One Deletion
    int maximumSumOneDeletion(const vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];
        int oneDel = 0; // Cannot delete sole element at i=0 and stay non-empty
        int ans = arr[0];

        for (int i = 1; i < n; i++) {
            oneDel = max(noDel, oneDel + arr[i]);
            noDel = max(arr[i], noDel + arr[i]);
            ans = max({ans, noDel, oneDel});
        }
        return ans;
    }

    // Variant B: Infosys Variant - Maximum Subarray Sum with At Most One Negation (-arr[i])
    int maximumSumOneNegation(const vector<int>& arr) {
        int n = arr.size();
        int noNeg = arr[0];
        int oneNeg = -arr[0];
        int ans = max(noNeg, oneNeg);

        for (int i = 1; i < n; i++) {
            int nextOneNeg = max({oneNeg + arr[i], noNeg - arr[i], -arr[i]});
            int nextNoNeg = max(arr[i], noNeg + arr[i]);
            oneNeg = nextOneNeg;
            noNeg = nextNoNeg;
            ans = max({ans, noNeg, oneNeg});
        }
        return ans;
    }
};

int main() {
    Solution sol;
    assert(sol.maximumSumOneDeletion({1, -2, 0, 3}) == 4);
    assert(sol.maximumSumOneDeletion({1, -2, -2, 3}) == 3);
    assert(sol.maximumSumOneDeletion({-1, -1, -1, -1}) == -1);
    assert(sol.maximumSumOneNegation({1, -5, 4}) == 10);
    assert(sol.maximumSumOneNegation({-10}) == 10);
    cout << "14_max_subarray_one_deletion_or_negation passed all tests!\n";
    return 0;
}
