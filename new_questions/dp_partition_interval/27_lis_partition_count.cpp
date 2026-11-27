#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Variant A: LeetCode 673 - Number of Longest Increasing Subsequences
    int findNumberOfLIS(const vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> len(n, 1), cnt(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, len[i]);
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            if (len[i] == maxLen) total += cnt[i];
        }
        return total;
    }

    // Variant B: Minimum Number of Strictly Increasing Subsequences to Partition Array (O(N log N))
    int minIncreasingPartitions(const vector<int>& nums) {
        vector<int> pileTails; // pileTails stays non-increasing? No! When replacing >= x in lower_bound, wait:
        // Wait: to partition into STRICTLY increasing subsequences:
        // Suppose nums = [5, 2, 6].
        // x=5 -> piles: [5]
        // x=2 -> cannot append 2 to 5 (2 <= 5). Start new pile: [5, 2]
        // x=6 -> can append to pile 0 (5 < 6) or pile 1 (2 < 6). Greedily append to largest tail < 6 (which is 5)!
        // Notice pileTails stays non-increasing (decreasing) if we replace the first element < x!
        // Let's verify: [5, 2, 6, 3, 7, 1]:
        // 5 -> [5]
        // 2 -> [5, 2]
        // 6 -> replace first < 6 (which is 5) -> [6, 2]
        // 3 -> replace first < 3 (which is 2) -> [6, 3]
        // 7 -> replace first < 7 (which is 6) -> [7, 3]
        // 1 -> no element < 1 -> push back -> [7, 3, 1]. Size = 3!
        for (int x : nums) {
            // Find first element strictly smaller than x in descending pileTails
            auto it = lower_bound(pileTails.begin(), pileTails.end(), x, [](int a, int b) {
                return a >= b; // find first a < x
            });
            if (it == pileTails.end()) {
                pileTails.push_back(x);
            } else {
                *it = x;
            }
        }
        return pileTails.size();
    }
};

int main() {
    Solution sol;
    assert(sol.findNumberOfLIS({1, 3, 5, 4, 7}) == 2);
    assert(sol.findNumberOfLIS({2, 2, 2, 2, 2}) == 5);
    assert(sol.minIncreasingPartitions({5, 2, 6, 3, 7, 1}) == 3);
    assert(sol.minIncreasingPartitions({1, 2, 3, 4}) == 1);
    cout << "27_lis_partition_count passed all tests!\n";
    return 0;
}
