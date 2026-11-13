#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class PartitionArrayMaxSum {
public:
    static int maxSumAfterPartitioning(const std::vector<int>& arr, int k) {
        int n = arr.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; ++i) {
            int maxVal = 0;
            for (int len = 1; len <= k && i - len >= 0; ++len) {
                maxVal = std::max(maxVal, arr[i - len]);
                dp[i] = std::max(dp[i], dp[i - len] + maxVal * len);
            }
        }
        return dp[n];
    }
};

int main() {
    std::vector<int> a1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    assert(PartitionArrayMaxSum::maxSumAfterPartitioning(a1, k1) == 84);

    std::vector<int> a2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    assert(PartitionArrayMaxSum::maxSumAfterPartitioning(a2, k2) == 83);

    std::vector<int> a3 = {1};
    int k3 = 1;
    assert(PartitionArrayMaxSum::maxSumAfterPartitioning(a3, k3) == 1);

    std::cout << "All Partition Array for Maximum Sum tests passed successfully!\n";
    return 0;
}

