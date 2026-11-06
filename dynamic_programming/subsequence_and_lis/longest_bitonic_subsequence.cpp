#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class LongestBitonicSubsequence {
public:
    static int longestBitonicSequence(const std::vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return n;

        // dp1[i]: length of LIS ending at i
        std::vector<int> dp1(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    dp1[i] = std::max(dp1[i], dp1[j] + 1);
                }
            }
        }

        // dp2[i]: length of LDS starting at i (LIS backward from n-1)
        std::vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (arr[j] < arr[i]) {
                    dp2[i] = std::max(dp2[i], dp2[j] + 1);
                }
            }
        }

        int maxBitonic = 0;
        for (int i = 0; i < n; ++i) {
            maxBitonic = std::max(maxBitonic, dp1[i] + dp2[i] - 1);
        }
        return maxBitonic;
    }
};

int main() {
    std::vector<int> a1 = {1, 2, 5, 3, 2};
    assert(LongestBitonicSubsequence::longestBitonicSequence(a1) == 5);

    std::vector<int> a2 = {1, 11, 2, 10, 4, 5, 2, 1};
    assert(LongestBitonicSubsequence::longestBitonicSequence(a2) == 6);

    std::vector<int> a3 = {10, 20, 30};
    assert(LongestBitonicSubsequence::longestBitonicSequence(a3) == 3);

    std::cout << "All Longest Bitonic Subsequence tests passed successfully!\n";
    return 0;
}

