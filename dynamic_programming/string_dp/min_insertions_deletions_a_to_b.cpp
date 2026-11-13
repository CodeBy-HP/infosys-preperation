#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

class MinInsertionsDeletions {
public:
    static int minDistance(const std::string& word1, const std::string& word2) {
        int n = word1.length();
        int m = word2.length();

        std::vector<int> prev(m + 1, 0);

        for (int i = 1; i <= n; ++i) {
            std::vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = std::max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        int lcs = prev[m];
        return (n - lcs) + (m - lcs);
    }
};

int main() {
    std::string w1 = "sea", w2 = "eat";
    assert(MinInsertionsDeletions::minDistance(w1, w2) == 2);

    std::string w3 = "leetcode", w4 = "etco";
    assert(MinInsertionsDeletions::minDistance(w3, w4) == 4);

    std::cout << "All Minimum Insertions or Deletions to Convert String A to B tests passed successfully!\n";
    return 0;
}

