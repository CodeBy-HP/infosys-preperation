#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maxProduct(const std::vector<std::string>& words) {
        // Map unique bitmask -> max length of word with that bitmask
        std::unordered_map<int, int> maskToMaxLen;

        for (const std::string& w : words) {
            int mask = 0;
            for (char c : w) {
                mask |= (1 << (c - 'a'));
            }
            maskToMaxLen[mask] = std::max(maskToMaxLen[mask], (int)w.size());
        }

        int maxProd = 0;
        for (const auto& [mask1, len1] : maskToMaxLen) {
            for (const auto& [mask2, len2] : maskToMaxLen) {
                // If disjoint (no shared characters)
                if ((mask1 & mask2) == 0) {
                    maxProd = std::max(maxProd, len1 * len2);
                }
            }
        }

        return maxProd;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words1 = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    std::cout << "Test 1: " << sol.maxProduct(words1) << " (Expected: 16)\n";

    std::vector<std::string> words2 = {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};
    std::cout << "Test 2: " << sol.maxProduct(words2) << " (Expected: 4)\n";

    return 0;
}
