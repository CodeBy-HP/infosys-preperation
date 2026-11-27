#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: Infosys Range Variant - Min (Y - X + 1) to remove >= ceil(N/2) elements
    int minRangeLengthToRemoveHalf(vector<int> arr) {
        int n = arr.size();
        int need = (n + 1) / 2;
        sort(arr.begin(), arr.end());

        int minRange = INT_MAX;
        for (int i = 0; i + need - 1 < n; i++) {
            int rangeLen = arr[i + need - 1] - arr[i] + 1;
            minRange = min(minRange, rangeLen);
        }
        return minRange;
    }

    // Variant B: Standard LeetCode 1338 - Min distinct integers to remove >= N/2 elements
    int minSetSize(const vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> freq;
        for (int x : arr) freq[x]++;

        vector<int> counts;
        counts.reserve(freq.size());
        for (auto& kv : freq) counts.push_back(kv.second);
        sort(counts.rbegin(), counts.rend());

        int removed = 0, distinctCnt = 0;
        for (int c : counts) {
            removed += c;
            distinctCnt++;
            if (removed * 2 >= n) return distinctCnt;
        }
        return distinctCnt;
    }
};

int main() {
    Solution sol;
    assert(sol.minRangeLengthToRemoveHalf({3, 3, 3, 5, 5, 5, 2, 2, 7, 7}) == 2); // [2, 3] removes 5 elements
    assert(sol.minRangeLengthToRemoveHalf({1, 1, 1, 1, 2}) == 1);
    assert(sol.minSetSize({3, 3, 3, 3, 5, 5, 5, 2, 2, 7}) == 2);
    cout << "39_reduce_array_size_half_range passed all tests!\n";
    return 0;
}
