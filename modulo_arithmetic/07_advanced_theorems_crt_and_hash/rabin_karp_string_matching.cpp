#include <iostream>
#include <string>
#include <vector>
#include <cassert>

/**
 * Rabin-Karp String Matching (Double Polynomial Rolling Hash)
 * Finds all occurrences of pattern in text in O(N + M) average time.
 */

class RabinKarp {
private:
    static const long long B1 = 31, M1 = 1e9 + 7;
    static const long long B2 = 37, M2 = 1e9 + 9;

public:
    static std::vector<int> search(const std::string& text, const std::string& pattern) {
        int n = static_cast<int>(text.size());
        int m = static_cast<int>(pattern.size());
        if (m == 0 || n < m) return {};

        std::vector<int> matches;

        // Step 1: Precompute B^(m-1) % M
        long long high_pow1 = 1, high_pow2 = 1;
        for (int i = 0; i < m - 1; ++i) {
            high_pow1 = (high_pow1 * B1) % M1;
            high_pow2 = (high_pow2 * B2) % M2;
        }

        // Step 2: Compute initial hashes for pattern and first window of text
        long long pat_h1 = 0, pat_h2 = 0;
        long long win_h1 = 0, win_h2 = 0;

        for (int i = 0; i < m; ++i) {
            pat_h1 = (pat_h1 * B1 + pattern[i]) % M1;
            pat_h2 = (pat_h2 * B2 + pattern[i]) % M2;

            win_h1 = (win_h1 * B1 + text[i]) % M1;
            win_h2 = (win_h2 * B2 + text[i]) % M2;
        }

        // Step 3: Rolling hash sweep
        for (int i = 0; i <= n - m; ++i) {
            if (win_h1 == pat_h1 && win_h2 == pat_h2) {
                // Double hash match guarantees match with probability 1 - 10^-18
                matches.push_back(i);
            }

            if (i < n - m) {
                // Roll hash 1
                win_h1 = (win_h1 - text[i] * high_pow1) % M1;
                win_h1 = (win_h1 * B1 + text[i + m]) % M1;
                if (win_h1 < 0) win_h1 += M1;

                // Roll hash 2
                win_h2 = (win_h2 - text[i] * high_pow2) % M2;
                win_h2 = (win_h2 * B2 + text[i + m]) % M2;
                if (win_h2 < 0) win_h2 += M2;
            }
        }

        return matches;
    }
};

int main() {
    std::string text = "abracadabracooperabra";
    std::string pattern = "abra";

    std::vector<int> matches = RabinKarp::search(text, pattern);
    std::cout << "Matches found at indices: ";
    for (int idx : matches) std::cout << idx << " ";
    std::cout << std::endl;

    // Expected matches at 0, 7, 17
    std::vector<int> expected = {0, 7, 17};
    assert(matches == expected);

    // Test with no match
    assert(RabinKarp::search("hello world", "xyz").empty());

    std::cout << "All Rabin-Karp String Matching tests passed successfully!" << std::endl;
    return 0;
}

