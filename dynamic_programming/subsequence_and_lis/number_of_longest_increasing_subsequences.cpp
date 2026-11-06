#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class NumberOfLIS {
public:
    static int findNumberOfLIS(const std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        std::vector<int> len(n, 1);
        std::vector<int> cnt(n, 1);

        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = std::max(maxLen, len[i]);
        }

        int totalCount = 0;
        for (int i = 0; i < n; ++i) {
            if (len[i] == maxLen) {
                totalCount += cnt[i];
            }
        }
        return totalCount;
    }
};

int main() {
    std::vector<int> n1 = {1, 3, 5, 4, 7};
    assert(NumberOfLIS::findNumberOfLIS(n1) == 2);

    std::vector<int> n2 = {2, 2, 2, 2, 2};
    assert(NumberOfLIS::findNumberOfLIS(n2) == 5);

    std::cout << "All Number of Longest Increasing Subsequences tests passed successfully!\n";
    return 0;
}

