#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class PrintLIS {
public:
    static std::vector<int> getLIS(const std::vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};

        std::vector<int> dp(n, 1);
        std::vector<int> parent(n);
        for (int i = 0; i < n; ++i) parent[i] = i;

        int maxLen = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                lastIndex = i;
            }
        }

        std::vector<int> lis;
        int curr = lastIndex;
        while (parent[curr] != curr) {
            lis.push_back(arr[curr]);
            curr = parent[curr];
        }
        lis.push_back(arr[curr]);
        std::reverse(lis.begin(), lis.end());
        return lis;
    }
};

int main() {
    std::vector<int> a1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<int> res1 = PrintLIS::getLIS(a1);
    assert(res1.size() == 4);
    // Elements must be strictly increasing
    for (size_t i = 1; i < res1.size(); ++i) {
        assert(res1[i] > res1[i - 1]);
    }

    std::vector<int> a2 = {5, 4, 11, 1, 16, 8};
    std::vector<int> res2 = PrintLIS::getLIS(a2);
    assert(res2.size() == 3);

    std::cout << "All Print Longest Increasing Subsequence tests passed successfully!\n";
    return 0;
}

