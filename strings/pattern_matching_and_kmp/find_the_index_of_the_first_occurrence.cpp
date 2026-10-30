#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMPPatternMatching {
private:
    vector<int> buildLPS(const string& pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1]; // Fallback to previous longest prefix
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

public:
    // =========================================================================
    // 1. KMP Linear String Search
    // Time Complexity: O(N + M) where N = haystack.size(), M = needle.size()
    // Space Complexity: O(M) for LPS array
    // =========================================================================
    int strStr(const string& haystack, const string& needle) {
        if (needle.empty()) return 0;
        int n = haystack.size();
        int m = needle.size();
        if (n < m) return -1;

        vector<int> lps = buildLPS(needle);

        int i = 0; // index for haystack
        int j = 0; // index for needle

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j; // Match found at (i - j)
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1]; // Shift pattern without rewinding i
                } else {
                    i++;
                }
            }
        }

        return -1;
    }
};

int main() {
    KMPPatternMatching solver;

    cout << "Test 1 (\"sadbutsad\", \"sad\"): " 
         << solver.strStr("sadbutsad", "sad") << " (Expected: 0)\n";

    cout << "Test 2 (\"leetcode\", \"leeto\"): " 
         << solver.strStr("leetcode", "leeto") << " (Expected: -1)\n";

    return 0;
}
