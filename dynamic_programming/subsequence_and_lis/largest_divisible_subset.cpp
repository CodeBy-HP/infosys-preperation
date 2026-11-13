#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class LargestDivisibleSubset {
public:
    static std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        std::sort(nums.begin(), nums.end());

        std::vector<int> dp(n, 1);
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        std::vector<int> result;
        int curr = lastIndex;
        while (parent[curr] != curr) {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }
        result.push_back(nums[curr]);
        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    std::vector<int> n1 = {1, 2, 3};
    std::vector<int> res1 = LargestDivisibleSubset::largestDivisibleSubset(n1);
    assert(res1.size() == 2);

    std::vector<int> n2 = {1, 2, 4, 8};
    std::vector<int> res2 = LargestDivisibleSubset::largestDivisibleSubset(n2);
    assert(res2.size() == 4);
    assert(res2 == std::vector<int>({1, 2, 4, 8}));

    std::cout << "All Largest Divisible Subset tests passed successfully!\n";
    return 0;
}

