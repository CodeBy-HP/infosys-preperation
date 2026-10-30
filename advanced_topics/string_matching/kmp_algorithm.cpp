#include <iostream>
#include <vector>
#include <string>

using namespace std;

class KMPStringMatching {
private:
    // =========================================================================
    // Computes the LPS (Longest Prefix which is also a Suffix) array
    // Time Complexity: O(M)
    // Space Complexity: O(M)
    // =========================================================================
    vector<int> computeLPS(const string& pattern) {
        int m = pattern.length();
        vector<int> lps(m, 0);

        int len = 0; // Length of previous longest prefix suffix
        int i = 1;

        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Fall back to previous longest prefix length without incrementing i
                    len = lps[len - 1];
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
    // 1. Returns index of First Occurrence (LeetCode 28: strStr)
    // Time Complexity: O(N + M)
    // Space Complexity: O(M)
    // =========================================================================
    int searchFirstOccurrence(const string& haystack, const string& needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0) return 0;
        if (n < m) return -1;

        vector<int> lps = computeLPS(needle);

        int i = 0; // Haystack pointer (never moves backwards!)
        int j = 0; // Needle pointer

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - m; // Found match at start index (i - m)
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1]; // Shift pattern using LPS
                } else {
                    i++;
                }
            }
        }

        return -1;
    }

    // =========================================================================
    // 2. Returns ALL starting indices where pattern occurs
    // Time Complexity: O(N + M)
    // Space Complexity: O(M)
    // =========================================================================
    vector<int> searchAllOccurrences(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<int> matches;

        if (m == 0 || n < m) return matches;

        vector<int> lps = computeLPS(pattern);
        int i = 0, j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) {
                matches.push_back(i - m);
                j = lps[j - 1]; // Continue searching for overlapping occurrences
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }

        return matches;
    }

    // =========================================================================
    // 3. Naive Brute-Force Baseline
    // Time Complexity: O(N * M)
    // Space Complexity: O(1)
    // =========================================================================
    int searchNaive(const string& haystack, const string& needle) {
        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }

        return -1;
    }
};

int main() {
    KMPStringMatching solver;

    string text = "onionionsys";
    string pattern = "onions";
    cout << "Test 1 (\"onionionsys\", \"onions\"):\n";
    cout << "  First Occurrence: " << solver.searchFirstOccurrence(text, pattern) << " (Expected: 3)\n";

    string text2 = "AABAACAADAABAABA";
    string pattern2 = "AABA";
    cout << "\nTest 2 (Find all occurrences of \"AABA\"):\n";
    vector<int> allMatches = solver.searchAllOccurrences(text2, pattern2);
    for (int idx : allMatches) {
        cout << "  Match at index: " << idx << "\n";
    }

    return 0;
}

