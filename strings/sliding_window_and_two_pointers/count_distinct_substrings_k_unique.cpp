#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cassert>

/**
 * Count Distinct Substrings with Exactly K Unique Characters
 * 
 * Provides both:
 * 1. Distinct unique substrings (deduplicated via Hash Set)
 * 2. Total substring occurrences using the AtMost(K) - AtMost(K - 1) sliding window
 */

class Solution {
public:
    // Formulation 1: Count distinct unique substring strings
    int countDistinctSubstringsWithKUnique(const std::string& s, int k) {
        int n = static_cast<int>(s.size());
        if (k <= 0 || k > 26 || n < k) return 0;

        std::unordered_set<std::string> unique_substrings;

        for (int i = 0; i < n; ++i) {
            std::vector<int> freq(26, 0);
            int distinct = 0;

            for (int j = i; j < n; ++j) {
                int char_idx = s[j] - 'a';
                if (freq[char_idx] == 0) {
                    distinct++;
                }
                freq[char_idx]++;

                if (distinct == k) {
                    unique_substrings.insert(s.substr(i, j - i + 1));
                } else if (distinct > k) {
                    // Extending further will only have >= distinct > k
                    break;
                }
            }
        }

        return static_cast<int>(unique_substrings.size());
    }

    // Formulation 2: Total occurrences using sliding window
    long long countSubstringsWithKUniqueOccurrences(const std::string& s, int k) {
        return countAtMostK(s, k) - countAtMostK(s, k - 1);
    }

private:
    long long countAtMostK(const std::string& s, int k) {
        if (k <= 0) return 0;
        int n = static_cast<int>(s.size());
        std::vector<int> freq(26, 0);
        int distinct = 0;
        int left = 0;
        long long total = 0;

        for (int right = 0; right < n; ++right) {
            if (freq[s[right] - 'a'] == 0) {
                distinct++;
            }
            freq[s[right] - 'a']++;

            while (distinct > k) {
                freq[s[left] - 'a']--;
                if (freq[s[left] - 'a'] == 0) {
                    distinct--;
                }
                left++;
            }

            total += (right - left + 1);
        }

        return total;
    }
};

int main() {
    Solution solver;

    // Test 1: "aab", k = 1
    // Distinct substrings with 1 unique char: "a", "aa", "b" -> count = 3
    {
        std::string s = "aab";
        int k = 1;
        int ans = solver.countDistinctSubstringsWithKUnique(s, k);
        std::cout << "Test 1: Expected = 3, Actual = " << ans << std::endl;
        assert(ans == 3);
    }

    // Test 2: "abacb", k = 2
    // Substrings with 2 unique chars:
    // "ab", "ba", "aba", "ac", "cb" -> total 5 distinct
    {
        std::string s = "abacb";
        int k = 2;
        int ans = solver.countDistinctSubstringsWithKUnique(s, k);
        std::cout << "Test 2: Expected = 5, Actual = " << ans << std::endl;
        assert(ans == 5);
    }

    // Test 3: Total occurrences sliding window test
    {
        std::string s = "aba";
        int k = 2;
        // Occurrences: "ab" (0..1), "ba" (1..2), "aba" (0..2) -> 3 occurrences
        long long occurrences = solver.countSubstringsWithKUniqueOccurrences(s, k);
        std::cout << "Test 3 (Occurrences): Expected = 3, Actual = " << occurrences << std::endl;
        assert(occurrences == 3);
    }

    std::cout << "All Count Distinct Substrings with K Unique Characters tests passed!" << std::endl;
    return 0;
}

