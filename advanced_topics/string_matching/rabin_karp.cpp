#include <iostream>
#include <vector>
#include <string>

using namespace std;

class RabinKarp {
private:
    static const int BASE = 256;
    static const long long MOD = 1e9 + 7;

public:
    // =========================================================================
    // 1. Single Rolling Hash with Spurious Collision Verification
    // Time Complexity: O(N + M) average, O(N * M) worst case
    // Space Complexity: O(1)
    // =========================================================================
    int searchFirstOccurrence(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();

        if (m == 0) return 0;
        if (n < m) return -1;

        long long patternHash = 0;
        long long windowHash = 0;
        long long highPower = 1; // BASE^(m - 1) % MOD

        for (int i = 0; i < m - 1; i++) {
            highPower = (highPower * BASE) % MOD;
        }

        // Calculate initial hashes for pattern and first text window
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (unsigned char)pattern[i]) % MOD;
            windowHash = (windowHash * BASE + (unsigned char)text[i]) % MOD;
        }

        // Slide the window over the text
        for (int i = 0; i <= n - m; i++) {
            if (patternHash == windowHash) {
                // Verify characters to eliminate false positives
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return i;
            }

            // Roll hash to the next character
            if (i < n - m) {
                windowHash = (windowHash - (unsigned char)text[i] * highPower) % MOD;
                windowHash = (windowHash * BASE + (unsigned char)text[i + m]) % MOD;
                if (windowHash < 0) windowHash += MOD;
            }
        }

        return -1;
    }

    // =========================================================================
    // 2. Returns ALL Occurrence Indices
    // Time Complexity: O(N + M) average
    // Space Complexity: O(1)
    // =========================================================================
    vector<int> searchAllOccurrences(const string& text, const string& pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<int> matches;

        if (m == 0 || n < m) return matches;

        long long patternHash = 0, windowHash = 0, highPower = 1;

        for (int i = 0; i < m - 1; i++) highPower = (highPower * BASE) % MOD;

        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (unsigned char)pattern[i]) % MOD;
            windowHash = (windowHash * BASE + (unsigned char)text[i]) % MOD;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patternHash == windowHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) matches.push_back(i);
            }

            if (i < n - m) {
                windowHash = (windowHash - (unsigned char)text[i] * highPower) % MOD;
                windowHash = (windowHash * BASE + (unsigned char)text[i + m]) % MOD;
                if (windowHash < 0) windowHash += MOD;
            }
        }

        return matches;
    }

    // =========================================================================
    // 3. Double Rolling Hash (Two Prime Modulos for Sub-10^-18 Collision Odds)
    // Time Complexity: O(N + M)
    // Space Complexity: O(1)
    // =========================================================================
    vector<int> searchDoubleHash(const string& text, const string& pattern) {
        const long long MOD1 = 1e9 + 7;
        const long long MOD2 = 1e9 + 9;
        const int B1 = 256;
        const int B2 = 313;

        int n = text.length();
        int m = pattern.length();
        vector<int> matches;

        if (m == 0 || n < m) return matches;

        long long patH1 = 0, patH2 = 0;
        long long winH1 = 0, winH2 = 0;
        long long p1 = 1, p2 = 1;

        for (int i = 0; i < m - 1; i++) {
            p1 = (p1 * B1) % MOD1;
            p2 = (p2 * B2) % MOD2;
        }

        for (int i = 0; i < m; i++) {
            patH1 = (patH1 * B1 + (unsigned char)pattern[i]) % MOD1;
            patH2 = (patH2 * B2 + (unsigned char)pattern[i]) % MOD2;
            winH1 = (winH1 * B1 + (unsigned char)text[i]) % MOD1;
            winH2 = (winH2 * B2 + (unsigned char)text[i]) % MOD2;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patH1 == winH1 && patH2 == winH2) {
                matches.push_back(i);
            }

            if (i < n - m) {
                winH1 = (winH1 - (unsigned char)text[i] * p1) % MOD1;
                winH1 = (winH1 * B1 + (unsigned char)text[i + m]) % MOD1;
                if (winH1 < 0) winH1 += MOD1;

                winH2 = (winH2 - (unsigned char)text[i] * p2) % MOD2;
                winH2 = (winH2 * B2 + (unsigned char)text[i + m]) % MOD2;
                if (winH2 < 0) winH2 += MOD2;
            }
        }

        return matches;
    }
};

int main() {
    RabinKarp solver;

    string text = "abracadabra";
    string pattern = "cad";
    cout << "Test 1 (\"abracadabra\", \"cad\"):\n";
    cout << "  First occurrence: " << solver.searchFirstOccurrence(text, pattern) << " (Expected: 4)\n";

    string text2 = "AABAACAADAABAABA";
    string pattern2 = "AABA";
    cout << "\nTest 2 Double Hash Occurrences of \"AABA\":\n";
    vector<int> matches = solver.searchDoubleHash(text2, pattern2);
    for (int idx : matches) {
        cout << "  Match at index: " << idx << "\n";
    }

    return 0;
}

