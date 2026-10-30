#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ShortestPalindrome {
public:
    // =========================================================================
    // 1. KMP LPS Prefix Symmetry
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    string shortestPalindrome(const string& s) {
        if (s.size() <= 1) return s;

        string rev = s;
        reverse(rev.begin(), rev.end());

        // Create combined string with separator
        string combined = s + "#" + rev;
        int n = combined.size();
        vector<int> lps(n, 0);

        for (int i = 1; i < n; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

        int longestPalindromePrefixLen = lps.back();
        string suffixToPrepend = s.substr(longestPalindromePrefixLen);
        reverse(suffixToPrepend.begin(), suffixToPrepend.end());

        return suffixToPrepend + s;
    }
};

int main() {
    ShortestPalindrome solver;

    cout << "\"aacecaaa\": " << solver.shortestPalindrome("aacecaaa") << " (Expected: \"aaacecaaa\")\n";
    cout << "\"abcd\":     " << solver.shortestPalindrome("abcd") << " (Expected: \"dcbabcd\")\n";

    return 0;
}
